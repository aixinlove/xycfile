//
//  xycfile.c
//  xycfile
//
//  Created by pengyunchou on 14/11/6.
//  Copyright (c) 2014年 swift. All rights reserved.
//

#include "xycfile.h"
#include <string.h>
int xycfile_open(xycfile_t *file,char *path,char *mode){
    file->rawfile=fopen(path, mode);
    memcpy(file->path, path, strlen(path));
    if (file->rawfile==NULL) {
        return -1;
    }
	return 0;
}
int xycfile_close(xycfile_t *file){
    return fclose(file->rawfile);
}
int xycfile_write_header(xycfile_t *file){
    return (int)fwrite(&(file->header), sizeof(file->header), 1, file->rawfile);
}
int xycfile_read_header(xycfile_t *file){
    return (int)fread(&(file->header), sizeof(file->header), 1, file->rawfile);
}

int xycfile_write(xycfile_t *file,xycfile_block_t *input){
    xycfile_block_t output;
    file->encfunc(input,&output);
	return (int)fwrite(&output, sizeof(output), 1, file->rawfile);
}
int xycfile_read(xycfile_t *file,xycfile_block_t *output){
    xycfile_block_t input;
    int readlen=(int)fread(&input, 1, sizeof(xycfile_block_t), file->rawfile);
    if(readlen==sizeof(xycfile_block_t)){
        file->decfunc(&input,output);
        return 0;
    };
    return -1;
}