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
    bool valid(TreeNode* root,long int l,long int r)
    {
        if(root==NULL)
        return 1;
        if(root->val<=l||root->val>=r)
        {
            return 0;
        }
        return valid(root->left,l,root->val)&&valid(root->right,root->val,r);
    }
    bool isValidBST(TreeNode* root) 
    {
        return valid(root,10LL*INT_MIN,10LL*INT_MAX);
    }
};