//
//  tea.h
//  ProtocolLib
//
//  Created by pengyunchou on 14-7-21.
//  Copyright (c) 2014年 kyx. All rights reserved.
//

#ifndef ProtocolLib_tea_h
#define ProtocolLib_tea_h
#include <stdint.h>
void tea_encrypt (uint32_t* v, uint32_t* k);
void tea_decrypt (uint32_t* v, uint32_t* k);
#endif
