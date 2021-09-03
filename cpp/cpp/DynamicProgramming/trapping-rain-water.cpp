//
//  trapping-rain-water.cpp
//  cpp
//
//  Created by ZouYa on 2021/9/3.
//

#include <stdio.h>
#include <vector>
using namespace::std;
/*
 https://leetcode-cn.com/problems/trapping-rain-water/
 */
class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if(size==0){
            return 0;
        }
        int i;
        vector<int> leftMax(size);
        leftMax[0] = height[0];
        for(i=1;i<size;i++){
            leftMax[i]=max(leftMax[i-1],height[i]);
        }
        vector<int> rightMax(size);
        rightMax[size-1] = height[size-1];
        for(i = size-2;i>=0;i--){
            rightMax[i]=max(rightMax[i+1],height[i]);
        }
        int ans=0;
        for(i=0;i<size;i++){
            ans += min(leftMax[i],rightMax[i])-height[i];
        }
        return ans;
    }
};
