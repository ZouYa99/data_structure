//
//  postorder-traversal.cpp
//  cpp
//
//  Created by ZouYa on 2021/9/3.
//

#include "TreeNode.hpp"
#include <vector>
using namespace::std;
/*
 给定一个二叉树，返回它的 后序 遍历。
 */
class Solution {
private:
    void postorder(TreeNode* root,vector<int>& ans){
        if(!root){
            return;
        }
        postorder(root->left,ans);
        postorder(root->right,ans);
        ans.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root,ans);
        return ans;
    }
};
