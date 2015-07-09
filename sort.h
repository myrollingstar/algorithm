//
//  sort.h
//  oj
//
//  Created by yanglong on 15/7/4.
//  Copyright (c) 2015年 yanglong. All rights reserved.
//

#ifndef __oj__sort__
#define __oj__sort__

#include <stdio.h>


void insertion_sort(int arr[], int length);

void insertion_sort_recur(int arr[], int length);


void selection_sort(int arr[], int length);

void merge_sort(int arr[], int length);

void quick_sort(int arr[], int length);

int get_inversion(int arr[], int length);

#endif /* defined(__oj__sort__) */
