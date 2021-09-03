//
//  inorder-traversal.cpp
//  cpp
//
//  Created by ZouYa on 2021/9/3.
//

#include "TreeNode.hpp"
#include <vector>
using namespace::std;
/*
 给定一个二叉树的根节点 root ，返回它的 中序 遍历。
 加入要遍历某个节点，先遍历该节点的左子树，再遍历该节点，再遍历该节点的右子树
 */
class Solution {
private:
    void inorder(TreeNode* root,vector<int>& ans){
        if(!root){
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        return ans;
    }
};
