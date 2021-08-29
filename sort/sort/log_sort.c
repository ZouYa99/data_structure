//
//  log_sort.c
//  sort
//
//  Created by ZouYa on 2021/8/29.
//

#include "log_sort.h"
//MARK: - 归并排序
void merge(int* array,int left,int mid,int right,int* temp){
    int i = left;
    int j = mid+1;
    int t = 0;
    while (i<=mid&&j<=right) {
        if (array[i]<array[j]) {
            temp[t++]=array[i++];
        }else{
            temp[t++]=array[j++];
        }
    }
    while (i<=mid) {
        temp[t++]=array[i++];
    }
    while (j<=right) {
        temp[t++]=array[j++];
    }
    t=0;
    i=left;
    while (i<=right) {
        array[i++]=temp[t++];
    }
}

void mergeSort(int* array,int low,int high,int* temp){
    if (low<high) {
        int mid = low + ((high-low)>>1);
        mergeSort(array, low, mid, temp);
        mergeSort(array, mid+1, high, temp);
        merge(array,low,mid,high,temp);
    }
}

//MARK: - 快速排序
void quickSort(int *array,int low,int high){
    if (low<high) {
        int i = low,j = high;
        int k = array[low];
        while (i<j) {
            while (i<j&&array[j]>k) {
                j--;
            }
            if (i<j) {
                array[i++]=array[j];
            }
            while (i<j&&array[i]<k) {
                i++;
            }
            if (i<j) {
                array[j--]=array[i];
            }
        }
        array[i] = k;
        quickSort(array, low, i);
        quickSort(array, i+1, high);
    }
}

//MARK: - 堆排序
void adjustForHeap(int* array,int target,int numsSize){
    int temp = target;
    int value = array[target];
    int k;
    for (k=target*2+1; k<numsSize; k=k*2+1) {
        if (k+1<numsSize&&array[k+1]>array[k]) {
            k=k+1;
        }
        if (array[k]>value) {
            array[temp]=array[k];
            temp=k;
        }else{
            break;
        }
    }
    array[temp]=value;
}

void heapSort(int *array,int numsSize){
    int i,j;
    for (i=numsSize/2-1; i>=0; i--) {
        adjustForHeap(array, i, numsSize);
    }
    for (j=numsSize-1; j>0; j--) {
        int temp = array[j];
        array[j]=array[0];
        array[0]=temp;
        adjustForHeap(array, 0, j);
    }
}
