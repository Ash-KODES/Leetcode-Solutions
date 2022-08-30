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
    TreeNode* Helper(vector<int>& nums,int lo,int hi)
    {
        if(lo>hi)
        return NULL;
        int mid=(lo+hi)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->right=Helper(nums,mid+1,hi);
        root->left=Helper(nums,lo,mid-1);
        return root;
    } 
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return Helper(nums,0,nums.size()-1);
    }
};