//
//  xycfilecript.h
//  xycfile
//
//  Created by pengyunchou on 14-11-13.
//  Copyright (c) 2014年 swift. All rights reserved.
//

#ifndef __xycfile__xycfilecript__
#define __xycfile__xycfilecript__

#include <stdio.h>
#include "xycfile.h"

typedef void (*xycfilecript_progress_t)(float progress);

void xycfilecript_encode(char *inupt,char *output,xycfile_enc_type_t cripttype,xycfilecript_progress_t progresscb);
void xycfilecript_decode(char *input,char *output,xycfile_enc_type_t cripttype,xycfilecript_progress_t progresscb);
#endif /* defined(__xycfile__xycfilecript__) */
