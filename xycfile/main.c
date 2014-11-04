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
int main(){
    xycfile_t file;
    printf("%d",sizeof(xycfile_header_t));
    memset(&file, 0x0, sizeof(file));
    memcpy(file.filepath, "a.txt", strlen("a.txt"));
    xycfile_open(&file, "w+");
    xycfile_write_header(&file);
    xycfile_close(&file);
    return 0;
}