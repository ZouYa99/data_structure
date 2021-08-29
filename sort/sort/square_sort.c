//
//  square_sort.c
//  sort
//
//  Created by ZouYa on 2021/8/29.
//

#include "square_sort.h"
//MARK: - 冒泡排序
void bubbleSort(int* array,int numsSize){
    int i,j;
    for (i=0; i<numsSize; i++) {
        for (j=0; j<numsSize-i-1; j++) {
            if (array[j]>array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

//MARK: - 选择排序
void selectSort(int* array,int numsSize){
    int i,j;
    for (i=0; i<numsSize; i++) {
        int index = i;
        for (j=i+1; j<numsSize; j++) {
            if (array[j]<array[index]) {
                index = j;
            }
        }
        int temp = array[index];
        array[index] = array[i];
        array[i] = temp;
    }
}

//MARK: - 插入排序
void insertSort(int* array,int numsSize){
    int i,j;
    for (i=0; i<numsSize; i++) {
        int target = array[i];
        for (j=i-1; j>=0&&array[j]>target; j--) {
            array[j+1]=array[j];
        }
        array[j+1]=target;
    }
}
