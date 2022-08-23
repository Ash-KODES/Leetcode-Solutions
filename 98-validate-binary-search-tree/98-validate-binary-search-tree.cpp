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
    //BST--> left < root->val
    //right> root->val
    //if this condtion is true for all--> valid
    //l==INT_MIN;
    //r==INT_MAX;
    //root
    //left==[intmin,root->val)
    //right==(root->val,Intmax]
    bool helper(TreeNode* root,long int left,long int right)
    {
        if(root==NULL)
        return true;
        if(root->val>left&&root->val<right)
        {
            bool leftcall=helper(root->left,left,root->val);
            bool rightcall=helper(root->right,root->val,right);
            return (leftcall&&rightcall);
        }
        else
        return false;
    }
    bool isValidBST(TreeNode* root) 
    {
        return helper(root,10LL*INT_MIN,10LL*INT_MAX);
    }
};