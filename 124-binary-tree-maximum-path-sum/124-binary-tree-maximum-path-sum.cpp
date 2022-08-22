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
    //traversal-dfs
    int helper(TreeNode* root,int& maxi)
    {
        //BASES
        if(root==NULL)
        return 0;
        int l=helper(root->left,maxi);
        int r=helper(root->right,maxi);
        int left=l>0?l:0; //15
        int right=r>0?r:0;  //7
        int total_sum=root->val+left+right; //42
        //cout<<total_sum<<endl;
        maxi=max(max(total_sum,root->val),maxi);
        return root->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) 
    {
        //Brute Force
        //Find all the paths,we can maximum
        //n-->max(left tree+ right tree + n->val)--all the nodes
        //O(n)*(n)
        //nodes*finding path sum of correspoding left tree and right tree
        //optimal
        int maxi=INT_MIN;
        int sum=helper(root,maxi);
        return maxi;
    }
};