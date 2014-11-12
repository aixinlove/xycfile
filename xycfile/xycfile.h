//
//  xycfile.h
//  xycfile
//
//  Created by pengyunchou on 14/11/6.
//  Copyright (c) 2014年 swift. All rights reserved.
//

#ifndef __xycfile__xycfile__
#define __xycfile__xycfile__

#include <stdio.h>
typedef struct{
    int32_t rawtype;
    int16_t enctype;
    int8_t password[16];
    int32_t rawlen;
} xycfile_header_t;

typedef void(^enc_dec_func_t)(int8_t input[],int8_t output[]);

typedef struct{
    enc_dec_func_t encfunc;
    enc_dec_func_t decfunc;
    xycfile_header_t header;
    FILE *rawfile;
    char path[256];
} xycfile_t;
int xycfile_open(xycfile_t *file,char *path,char *mode);
int xycfile_write_header(xycfile_t *file);
int xycfile_read_header(xycfile_t *file);
int xycfile_write(xycfile_t *file,int8_t *buff,int len);
int xycfile_read(xycfile_t *file,int8_t *buff,int expected);
#endif /* defined(__xycfile__xycfile__) */
