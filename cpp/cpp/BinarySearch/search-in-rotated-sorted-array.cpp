//
//  search-in-rotated-sorted-array.cpp
//  cpp
//
//  Created by ZouYa on 2021/9/3.
//

#include <stdio.h>
#include <vector>
using namespace::std;
/*
 整数数组 nums 按升序排列，数组中的值 互不相同 。
 在传递给函数之前，nums 在预先未知的某个下标 k
 （0 <= k < nums.length）上进行了 旋转，使数组变为
 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。
 例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。
 给你 旋转后 的数组 nums 和一个整数 target ，
 如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int i=0,j=size-1,mid;
        while(i<=j){
            mid = i+((j-i)>>1);
            if(nums[mid]==target){
                return mid;
            }
            if(nums[0]<=nums[mid]){
                if(nums[0]<=target&&target<nums[mid]){
                    j = mid - 1;
                }else{
                    i = mid + 1;
                }
            }else{
                if(nums[mid]<target&&target<=nums[size-1]){
                    i = mid + 1;
                }else{
                    j = mid - 1;
                }
            }
        }
        return -1;
    }
};

/*
 int search(int* nums, int numsSize, int target){
     if(numsSize==0){
         return -1;
     }
     int low=0,high=numsSize-1,mid;
     while(low<high){
         mid = low + ((high-low)>>1);
         if(nums[mid]>nums[high]){
             low = mid + 1;
         }else{
             high = mid;
         }
     }
     int point = low;
     if(target>=nums[0]){
         low = 0;
         high = point-1;
     }
     if(target<=nums[numsSize-1]){
         low = point;
         high = numsSize-1;
     }
     while(low<=high){
         mid = low + ((high-low)>>1);
         if(nums[mid]==target){
             return mid;
         }else if(nums[mid]>target){
             high = mid - 1;
         }else{
             low = mid + 1;
         }
     }
     return -1;
 }
 */
