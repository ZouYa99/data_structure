//
//  3-sum.cpp
//  cpp
//
//  Created by ZouYa on 2021/9/3.
//

#include <stdio.h>
#include <vector>
using namespace::std;
/*
 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        if(size<3){
            return {};
        }
        sort(nums.begin(),nums.end());
        vector<vector<int>> answer;
        int first;
        for(first=0;first<size;first++){
            if(first>0&&nums[first]==nums[first-1]){
                continue;
            }
            int second = first + 1;
            int third = size - 1;
            int target = -nums[first];
            for(;second<size;second++){
                if(second>first+1&&nums[second-1]==nums[second]){
                    continue;
                }
                while(second<third&&nums[second]+nums[third]>target){
                    third--;
                }
                if(second==third){
                    break;
                }
                if(nums[second]+nums[third]==target){
                    answer.push_back({nums[first],nums[second],nums[third]});
                }
            }
        }
        return answer;
    }
};

