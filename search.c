//
//  search.c
//  oj
//
//  Created by yanglong on 15/7/4.
//  Copyright (c) 2015年 yanglong. All rights reserved.
//

#include "search.h"

int binary_search_recur(int arr[], int low, int high, int value){
    if(low <= high){
        int middle = (low + high) / 2;
        if(arr[middle] == value){
            return middle;
        }
        else if (arr[middle] > value){
            return binary_search_recur(arr, low, middle - 1, value);
        }
        else{
            return binary_search_recur(arr, middle + 1, high, value);
        }
    }
    return -1;
}

int binary_search(int arr[], int length, int value){
    return binary_search_recur(arr, 0, length - 1, value);
}
