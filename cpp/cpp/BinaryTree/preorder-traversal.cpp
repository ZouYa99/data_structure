//
//  preorder-traversal.cpp
//  cpp
//
//  Created by ZouYa on 2021/9/3.
//

#include "TreeNode.hpp"
#include <vector>
using namespace::std;
/*
 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
 */
class Solution {
private:
    void preorder(TreeNode* root,vector<int>& ans){
        if(!root){
            return;
        }
        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root,ans);
        return ans;
    }
};

/*
 迭代法：
 class Solution {
 public:
     vector<int> preorderTraversal(TreeNode* root) {
         vector<int> res;
         if (root == nullptr) {
             return res;
         }

         stack<TreeNode*> stk;
         TreeNode* node = root;
         while (!stk.empty() || node != nullptr) {
             while (node != nullptr) {
                 res.emplace_back(node->val);
                 stk.emplace(node);
                 node = node->left;
             }
             node = stk.top();
             stk.pop();
             node = node->right;
         }
         return res;
     }
 };
 */
