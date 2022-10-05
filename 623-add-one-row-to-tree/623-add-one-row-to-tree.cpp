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
    void helper(TreeNode* root, int val, int depth)
    {
        if(root==NULL)
        return ;
        if(depth==1)
        {
            TreeNode* nodel=new TreeNode(val);
            TreeNode* noder=new TreeNode(val);
            nodel->left=root->left;
            noder->right=root->right;
            root->left=nodel;
            root->right=noder;
            return ;
        }
        helper(root->left,val,depth-1);
        helper(root->right,val,depth-1);
        return ;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) 
    {
        if(depth==1)
        {
            TreeNode* node=new TreeNode(val);
            node->left=root;
            return node;
        }
        helper(root,val,depth-1);
        return root;
    }
};