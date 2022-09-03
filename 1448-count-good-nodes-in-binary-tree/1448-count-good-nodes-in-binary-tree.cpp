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
    void helper(TreeNode* root,int maxi,int &count)
    {
        if(root==NULL)
        return ;
        if(root->val>=maxi)
        {
            count++;
            maxi=root->val;
        }
        helper(root->left,maxi,count);
        helper(root->right,maxi,count);
    }
    int goodNodes(TreeNode* root) 
    {
         int maxi=INT_MIN;
         int count=0;
         helper(root,maxi,count);
         return count;
    }
};