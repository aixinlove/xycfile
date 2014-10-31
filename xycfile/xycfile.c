//
//  xycfile.c
//  xycfile
//
//  Created by pengyunchou on 14/10/30.
//  Copyright (c) 2014年 swift. All rights reserved.
//

#include "xycfile.h"

/*
 * private functions
 */
int xycfile_read_header(xycfile_t *file){
    size_t size=fread(&(file->header), sizeof(file->header), 1, file->rawfile);
    if (size!=sizeof(file->header)) {
        return -1;
    }
    return 0;
}
int xycfile_write_header(xycfile_t *file){
    size_t size=fwrite(&(file->header), sizeof(file->header), 1, file->rawfile);
    if (size!=sizeof(file->header)) {
        return -1;
    }
    return 0;
}
/*
 * public functions
 */
int xycfile_open(xycfile_t *file){
    file->rawfile=fopen(file->filepath, "r+");
    if (file->rawfile==NULL) {
        return -1;
    }
    return 0;
}

int xycfile_close(xycfile_t *file){
    return fclose(file->rawfile);
}

int xycfile_write(xycfile_t *file,xycfile_enc_dec_block_t *block){
    
    return 0;
}
int xycfile_read(xycfile_t *file,xycfile_enc_dec_block_t *block){
    
    return 0;
}