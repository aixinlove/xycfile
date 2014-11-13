//
//  main.c
//  xycfile
//
//  Created by pengyunchou on 14/11/3.
//  Copyright (c) 2014年 swift. All rights reserved.
//

#include <stdio.h>
#include "xycfile.h"
#include <string.h>
void enc(xycfile_block_t *input,xycfile_block_t *output){
    memcpy(output, input, sizeof(xycfile_block_t));
}
int main(){
    xycfile_t file;
    file.encfunc=enc;
    xycfile_open(&file, "a.txt", "w");
    file.header.enctype=xycfile_enc_type_echo;
    file.header.rawtype=xycfile_rawtype_txt;
    xycfile_write_header(&file);
    char *hello="hello world";
    
    xycfile_close(&file);
    return 0;
}