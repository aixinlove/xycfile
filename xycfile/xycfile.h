//
//  xycfile.h
//  xycfile
//
//  Created by pengyunchou on 14/10/30.
//  Copyright (c) 2014年 swift. All rights reserved.
//

#ifndef __xycfile__xycfile__
#define __xycfile__xycfile__

#include <stdio.h>

typedef struct{
    int8_t version;
    int8_t encoding;
    int16_t type;
    int64_t createtime;
    int64_t updatetime;
    int8_t password[64];
    int8_t desc[1024];
    int8_t xyc[13];
    int32_t contentlen;
} xycfile_header_t;

typedef struct{
    int8_t data[4];
} xycfile_enc_dec_block_t;

typedef  void (*xycfile_enc_dec_func_t)(xycfile_enc_dec_block_t* input, xycfile_enc_dec_block_t* output);

typedef struct{
    xycfile_enc_dec_func_t encfunc;
    xycfile_enc_dec_func_t decfunc;
    char filepath[1024];
    FILE *rawfile;
    xycfile_header_t header;
} xycfile_t;
int xycfile_open(xycfile_t *file);
int xycfile_close(xycfile_t *file);
int xycfile_write(xycfile_t *file,xycfile_enc_dec_block_t *block);
int xycfile_read(xycfile_t *file,xycfile_enc_dec_block_t *block);
#endif /* defined(__xycfile__xycfile__) */
