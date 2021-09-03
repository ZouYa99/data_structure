//
//  two_sum.cpp
//  cpp
//
//  Created by ZouYa on 2021/8/30.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
 你可以按任意顺序返回答案。
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        int size = nums.size();
        for(int i=0;i<size;i++){
            if(map.count(target-nums[i])){
                return {map[target-nums[i]],i};
            }else{
                map.insert({nums[i],i});
            }
        }
        return {};
    }
};
