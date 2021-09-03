//
//  maximum-subarray.cpp
//  cpp
//
//  Created by ZouYa on 2021/9/3.
//

#include <stdio.h>
#include <vector>
using namespace::std;
/*
 给定一个整数数组 nums ，
 找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int maxSum=nums[0],count=nums[0];
        for(int i=1;i<size;i++){
            if(count<0){
                count=nums[i];
            }else{
                count += nums[i];
            }
            maxSum=max(maxSum,count);
        }
        return maxSum;
    }
};
