#include <stdio.h>
#include "sort.h"
#include "search.h"
#include "divide_conquer.h"

void print_array(int arr[], int length){
    int i;
    for(i = 0; i < length;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    int arr[] = {-3,-2,-1};
    int length = 3;
//    int value =  1;
//    insertion_sort(arr, length);
//    selection_sort(arr, length);
//    merge_sort(arr, length);
//    insertion_sort_recur(arr, length);
//    quick_sort(arr, length);
//    print_array(arr, length);
    struct triple t = find_max_subarray(arr, length);
    printf("%d %d %d\n", t.from, t.to, t.sum);
//    printf("%d\n", get_inversion(arr, length));
//    printf("%d\n", binary_search(arr, length, value));
//    return 0;
//    char c = '1';
   
//    printf("%d", c + 'A');
    
}


