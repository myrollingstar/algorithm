//
//  sort.c
//  oj
//
//  Created by yanglong on 15/7/4.
//  Copyright (c) 2015年 yanglong. All rights reserved.
//

#include "sort.h"

void insertion_sort(int arr[], int length){
    int i;
    int j;
    int key;
    for(i = 1; i < length;i++){
        j = i - 1;
        key = arr[i];
        while(j >= 0 && key < arr[j]){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    
}

void insertion_sort_recur(int arr[], int length){
    if(length > 1){
        insertion_sort(arr, length - 1);
        int i = length - 1;
        int j = i - 1;
        int key = arr[i];
        while(j >= 0 && key < arr[j]){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        
    }
}

void selection_sort(int arr[], int length){
    int i;
    int j;
    int temp;
    for(i = 0; i < length - 1; i++){
        int min = i;
        for(j = i + 1; j < length; j++){
            if(arr[min] > arr[j]){
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void merge(int arr[], int l, int m, int h){
    int llength = m - l + 1;
    int rlength = h - m;
    
    int larr[llength];
    int rarr[rlength];
    
    int i,j;
    
    int k = l;
    i = 0;
    while(k <= m){
        larr[i] = arr[k];
        i++;
        k++;
    }
    
    k = m + 1;
    i = 0;
    while(k <= h){
        rarr[i] = arr[k];
        i++;
        k++;
    }
    
    i = 0;
    j = 0;
    k = l;
    while(i < llength && j < rlength){
        if(larr[i] <= rarr[j]){
            arr[k] = larr[i];
            i++;
        }
        else{
            arr[k] = rarr[j];
            j++;
        }
        k++;
    }
    
    
    for(; i < llength;i++){
        arr[k] = larr[i];
        k++;
    }
    
    for(; j < rlength;j++){
        arr[k] = rarr[j];
        k++;
    }
    
}

void merge_sort_rec(int arr[], int low, int high){
    if(low < high){
   
        int middle = (low + high) / 2;
        
        merge_sort_rec(arr, low, middle);
        merge_sort_rec(arr, middle + 1, high);
        merge(arr, low, middle, high);
        
    }
}

void merge_sort(int arr[], int length){
    int l = 0;
    int h = length - 1;
    merge_sort_rec(arr, l, h);
}

int merge_inversions(int arr[], int l, int m, int h){
    int inversions = 0;
    
    int llength = m - l + 1;
    int rlength = h - m;
    
    int larr[llength];
    int rarr[rlength];
    
    int i,j;
    
    int k = l;
    i = 0;
    while(k <= m){
        larr[i] = arr[k];
        i++;
        k++;
    }
    
    k = m + 1;
    i = 0;
    while(k <= h){
        rarr[i] = arr[k];
        i++;
        k++;
    }
    
    i = 0;
    j = 0;
    k = l;
    while(i < llength && j < rlength){
        if(larr[i] <= rarr[j]){
            arr[k] = larr[i];
            i++;
        }
        else{
            arr[k] = rarr[j];
            j++;
            inversions++;
        }
        k++;
    }
    
    
    for(; i < llength;i++){
        arr[k] = larr[i];
        k++;
    }
    
    for(; j < rlength;j++){
        arr[k] = rarr[j];
        k++;
    }

    return inversions;
    
}

int get_inversion_rec(int arr[], int low, int high){
    if(low < high){
        int middle = (low + high) / 2;
        int l = get_inversion_rec(arr, low, middle);
        int r = get_inversion_rec(arr, middle + 1, high);
        return l + r + merge_inversions(arr, low, middle, high);
    }
    return 0;
}


int get_inversion(int arr[], int length){
    int l = 0;
    int h = length - 1;
    return get_inversion_rec(arr, l, h);
}

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = low + 1;
    while(j <= high){
        if(arr[j] < pivot){
            i++;
            int t = arr[j];
            arr[j] = arr[i];
            arr[i] = t;
        }
        j++;
    }
    int t = arr[i];
    arr[i] = arr[low];
    arr[low] = t;
    return i;

}

void quick_sort_recur(int arr[], int low, int high){
    if(low < high){
        int p = partition(arr, low, high);
        quick_sort_recur(arr, low, p - 1);
        quick_sort_recur(arr, p + 1, high);
    }
    
}

void quick_sort(int arr[], int length){
    quick_sort_recur(arr, 0, length - 1);
}



