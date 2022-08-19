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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root==NULL)
        return ans;
        q.push(root);
        while(!q.empty())
        {
            int loop=q.size();
            vector<int> level;
            for(int i=0;i<loop;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left!=NULL)
                q.push(curr->left);
                if(curr->right!=NULL)
                q.push(curr->right);
                level.push_back(curr->val);
            }
            ans.push_back(level);
        }
        return ans;    
    }
};