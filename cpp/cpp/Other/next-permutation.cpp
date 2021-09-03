//
//  next-permutation.cpp
//  cpp
//
//  Created by ZouYa on 2021/9/3.
//

#include <stdio.h>
#include <vector>
using namespace::std;
/*
 实现获取 下一个排列 的函数，
 算法需要将给定数字序列重新排列成字典序中下一个更大的排列
 （即，组合出下一个更大的整数）。
 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
 必须 原地 修改，只允许使用额外常数空间。
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        if(size==1){
            return;
        }
        int i=size-2;
        while(i>=0&&nums[i]>=nums[i+1]){
            i--;
        }
        if(i>=0){
            int j = size-1;
            while(j>=0&&nums[j]<=nums[i]){
                j--;
            }
            if(j>=0){
                swap(nums[i],nums[j]);
            }
        }
        reverse(nums.begin()+i+1,nums.end());
    }
};
