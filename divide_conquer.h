//
//  divide_conquer.h
//  oj
//
//  Created by yanglong on 15/7/9.
//  Copyright (c) 2015年 yanglong. All rights reserved.
//

#ifndef __oj__divide_conquer__
#define __oj__divide_conquer__

#include <stdio.h>

struct triple{
    int from,to,sum;
};

struct triple find_max_subarray(int arr[], int length);

#endif /* defined(__oj__divide_conquer__) */
