//
//  level-order-traversal.cpp
//  cpp
//
//  Created by ZouYa on 2021/9/4.
//

#include "TreeNode.hpp"
#include <vector>
#include <queue>
using namespace::std;
/*
 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int curSize = q.size();
            ans.push_back(vector<int>());
            for(int i=1;i<=curSize;i++){
                TreeNode* cur = q.front();q.pop();
                ans.back().push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
        return ans;
    }
};
