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
    // helper function-returning me the sum of nodes of tree in which root is represented by "root"
    int helper(TreeNode* root,int& tilt)
    {
        //BASE CASES
        if(root==NULL)
        return 0;
        int left=helper(root->left,tilt);
        int right=helper(root->right,tilt);
        tilt+=abs(left-right);
        return root->val+left+right;
    }
    int findTilt(TreeNode* root) 
    {
        //Brute force-
        //(finding tilts value )*(node)
        //o(n)*o(n)=o(n2)
        
        //optimal-
        int tilt=0;
        int sum=helper(root,tilt);
        return tilt;
    }
};