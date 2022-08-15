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
    int height(TreeNode* root)
    {
      if(root==NULL)
      return 0;
      int left=height(root->left);
      int right=height(root->right);
      if(left==-1||right==-1)
      return -1;
      if(abs(left-right)>1)
      return -1;
      return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) 
    {
      //abs(lh-rh)<=1
      int val=height(root);
      if(val==-1)
      return 0;
      else
      return 1;
    }
};