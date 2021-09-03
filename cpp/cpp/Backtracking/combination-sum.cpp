//
//  combination-sum.cpp
//  cpp
//
//  Created by ZouYa on 2021/9/3.
//

#include <stdio.h>
#include <vector>
using namespace::std;
/*
 给定一个无重复元素的正整数数组 candidates 和一个正整数 target ，
 找出 candidates 中所有可以使数字和为目标数 target 的唯一组合。
 candidates 中的数字可以无限制重复被选取。
 如果至少一个所选数字数量不同，则两种组合是唯一的。
 对于给定的输入，保证和为 target 的唯一组合数少于 150 个。
 */
class Solution {
private:
    void bfs(vector<int>& candidates,vector<int>& combine,vector<vector<int>>& ans,int target,int index){
        if(index==candidates.size()) return;
        if(target==0){
            ans.emplace_back(combine);
            return;
        }
        bfs(candidates,combine,ans,target,index+1);
        if(target-candidates[index]>=0){
            combine.push_back(candidates[index]);
            bfs(candidates,combine,ans,target-candidates[index],index);
            combine.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combine;
        vector<vector<int>> ans;
        bfs(candidates,combine,ans,target,0);
        return ans;
    }
};
