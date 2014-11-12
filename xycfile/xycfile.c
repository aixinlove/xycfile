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
	return 0;
}
int xycfile_write_header(xycfile_t *file){
    return (int)fwrite(&(file->header), sizeof(file->header), 1, file->rawfile);
}
int xycfile_read_header(xycfile_t *file){
    return (int)fread(&(file->header), sizeof(file->header), 1, file->rawfile);
}

int xycfile_write(xycfile_t *file,int8_t *inupt,int len){
    int8_t output[len];
    file->encfunc(inupt,output);
	return (int)fwrite(output, len, 1, file->rawfile);
}
int xycfile_read(xycfile_t *file,int8_t *output,int expected){
    int8_t input[expected];
    if(fread(input, expected, 1, file->rawfile)==expected){
        file->decfunc(input,output);
        return 0;
    };
    return -1;
}