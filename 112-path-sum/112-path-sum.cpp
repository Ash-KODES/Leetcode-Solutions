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
    bool helper(TreeNode* root,int sum)
    {
        // BASE CASES
        if(root==NULL)
        return false;
        if(sum==root->val&&root->left==NULL&&root->right==NULL)
        return true;
        //case 1-
        bool left=helper(root->left,sum-root->val);
        //case 2-
        bool right=helper(root->right,sum-root->val);
        return left||right;
    }
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        //approach
        //1.trying out all paths and will check if any path gives mr the 
        //target sum or not
        
        return helper(root,targetSum);
        
    }
};