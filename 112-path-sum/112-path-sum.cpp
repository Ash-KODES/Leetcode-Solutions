/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool Helper(TreeNode* root,int targetSum)
    {
        if(root->left==NULL&&root->right==NULL)
        {
            return targetSum==root->val; 
        }
        bool l=false;
        if(root->left!=NULL)
        l=Helper(root->left,targetSum-root->val);
        bool r=false;
        if(root->right!=NULL)
        r=Helper(root->right,targetSum-root->val);
        return l||r;
    }
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if(root==NULL)
        return false;
        return Helper(root,targetSum);   
    }
};