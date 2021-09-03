//
//  binary-tree-right-side-view.cpp
//  cpp
//
//  Created by ZouYa on 2021/9/3.
//

#include "TreeNode.hpp"
#include <vector>
#include <queue>
using namespace::std;
/*
 给定一个二叉树的 根节点 root，想象自己站在它的右侧，
 按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int curSize = q.size();
            for(int i=0;i<curSize;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                if(i==curSize-1){
                    ans.push_back(node->val);
                }
            }
        }
        return ans;
    }
};
