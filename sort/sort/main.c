//
//  main.c
//  sort
//
//  Created by ZouYa on 2021/8/17.
//

#include <stdio.h>
#include "square_sort.h"
#include "log_sort.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int array[9] = {5,4,7,3,8,2,1,9,6};
    int temp[9];
    mergeSort(array, 0, 8, temp);
    for (int i=0; i<9; i++) {
        printf("%d ",array[i]);
    }
    printf("\n");
    return 0;
}
