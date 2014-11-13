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

typedef enum{
    xycfile_enc_type_echo=0x0000,
    xycfile_enc_type_xor=0x0001,
    xycfile_enc_type_tea=0x0002,
    xycfile_enc_type_xtea=0x003,
    xycfile_enc_type_xxtea=0x004
}xycfile_enc_type_t;
typedef enum{
    xycfile_rawtype_txt=0x010001,
    xycfile_rawtype_jpg=0x020002,
    xycfile_rawtype_png=0x020003,
    xycfile_rawtype_pdf=0x020004
} xycfile_rawtype_t;
typedef struct{
    int32_t rawtype;
    int16_t enctype;
    int8_t password[16];
    int32_t rawlen;
} xycfile_header_t;
typedef union{
    int8_t data[16];
    int32_t idata[4];
} xycfile_block_t;

typedef void (*enc_dec_func_t)(xycfile_block_t *input,xycfile_block_t *output);

typedef struct{
    enc_dec_func_t encfunc;
    enc_dec_func_t decfunc;
    xycfile_header_t header;
    FILE *rawfile;
    char path[256];
} xycfile_t;

int xycfile_open(xycfile_t *file,char *path,char *mode);
int xycfile_close(xycfile_t *file);
int xycfile_write_header(xycfile_t *file);
int xycfile_read_header(xycfile_t *file);
int xycfile_write(xycfile_t *file,xycfile_block_t *input);
int xycfile_read(xycfile_t *file,xycfile_block_t *output);
#endif /* defined(__xycfile__xycfile__) */
