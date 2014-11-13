//
//  xor.c
//  ProtocolLib
//
//  Created by pengyunchou on 14-7-26.
//  Copyright (c) 2014年 kyx. All rights reserved.
//

#include <stdio.h>
#include "xor.h"
//key 长度为4个int32
//每次加密或者解密4个int32
void xor_encrypt (uint32_t* v, uint32_t* k){
    for (int i=0; i<4; i++) {
        v[i]^=k[i];
    }
}