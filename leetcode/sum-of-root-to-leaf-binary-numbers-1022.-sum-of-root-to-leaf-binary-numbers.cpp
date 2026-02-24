// Problem: 1022. Sum of Root To Leaf Binary Numbers
// URL: https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
// Language: cpp
class Solution {
public:
    int sumRootToLeaf(TreeNode* root,int val=0) {
        if(root==nullptr) return 0;
        val=val<<1|root->val;
        if(root->left==nullptr && root->right==nullptr) return val;
        return sumRootToLeaf(root->left,val)+sumRootToLeaf(root->right,val);
    }
};
