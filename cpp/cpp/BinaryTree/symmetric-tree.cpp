//
//  symmetric-tree.cpp
//  cpp
//
//  Created by ZouYa on 2021/9/3.
//

#include "TreeNode.hpp"
/*
 给定一个二叉树，检查它是否是镜像对称的。
 */
class Solution {
private:
    bool symmetricTree(TreeNode* left,TreeNode* right){
        if(left&&right){
            if(left->val!=right->val){
                return false;
            }
            return symmetricTree(left->left,right->right)&&symmetricTree(left->right,right->left);
        }else if(left==nullptr&&right==nullptr){
            return true;
        }else{
            return false;
        }
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root){
            return false;
        }
        return symmetricTree(root->left,root->right);
    }
};
