//
//  divide_conquer.c
//  oj
//
//  Created by yanglong on 15/7/9.
//  Copyright (c) 2015年 yanglong. All rights reserved.
//

#include "divide_conquer.h"

struct triple find_max_crossing_subarray(int arr[], int middle, int low, int high){
    int i;
    int left_sum = 0;
    int left_max = -INT32_MAX;
    int left_index = middle;
    for(i = middle; i >= low; i--){
        left_sum += arr[i];
        if(left_sum > left_max){
            left_max = left_sum;
            left_index = i;
        }
    }
    
    int right_sum = 0;
    int right_max = -INT32_MAX;
    int right_index = middle + 1;
    for(i = middle + 1; i <= high; i++){
        right_sum += arr[i];
        if(right_sum > right_max){
            right_max = right_sum;
            right_index = i;
        }
    }
    
    struct triple t;
    t.from = left_index;
    t.to = right_index;
    t.sum = left_sum + right_sum;
    
    return t;
}

struct triple find_max_subarray_recur(int arr[], int low, int high){
    if(low < high){
        int middle = (low + high) / 2;
        struct triple left_triple = find_max_subarray_recur(arr, low, middle);
        struct triple right_triple = find_max_subarray_recur(arr, middle + 1, high);
        struct triple crossing_triple = find_max_crossing_subarray(arr, middle, low, high);
        struct triple max_triple = left_triple;
        if(right_triple.sum > max_triple.sum){
            max_triple = right_triple;
        }
        if(crossing_triple.sum > max_triple.sum){
            max_triple = crossing_triple;
        }
        return max_triple;
    }
    else{
        struct triple t;
        t.from = low;
        t.to = low;
        t.sum = arr[low];
        return t;
    }
}

struct triple find_max_subarray(int arr[], int length){
    return find_max_subarray_recur(arr, 0, length - 1);
}