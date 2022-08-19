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
    vector<TreeNode*> helper(int n)
    {
        
        vector<TreeNode*> v;
        //base case
        if(n==1)
        {
            TreeNode* root=new TreeNode(0);
            v.push_back(root);
            return v;
        }
        // all other odd cases
        for(int i=1;i<n;i+=2)
        {
            vector<TreeNode*> left=helper(i);
            vector<TreeNode*> right=helper(n-i-1);
            for(auto l:left)
            {
                for(auto r:right)
                {
                    TreeNode* root=new TreeNode(0);
                    root->left=l;
                    root->right=r;
                    v.push_back(root);
                }
            }
        }
        return v;
    }
    vector<TreeNode*> allPossibleFBT(int n) 
    {
        vector<TreeNode*> ans;
        if(n%2==0)
        return ans;
        ans=helper(n);
        return ans;
    }
};