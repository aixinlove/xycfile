//
//  xtea.h
//  ProtocolLib
//
//  Created by pengyunchou on 14-7-21.
//  Copyright (c) 2014年 kyx. All rights reserved.
//

#ifndef ProtocolLib_xtea_h
#define ProtocolLib_xtea_h
#include <stdint.h>
void xtea_decrypt(unsigned int num_rounds, uint32_t v[2], uint32_t const key[4]);
void xtea_encrypt(unsigned int num_rounds, uint32_t v[2], uint32_t const key[4]);
#endif
