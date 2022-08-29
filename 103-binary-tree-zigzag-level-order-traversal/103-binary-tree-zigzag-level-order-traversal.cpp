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
    vector<vector<int>> helper(TreeNode* root)
    {
        queue<TreeNode*> q;
        vector<vector<int>> v;
        q.push(root);
        int flag=0;
        while(true)
        {
            int loop=q.size();
            if(loop==0)
            break;
            vector<int> temp;
            while(loop--)
            {
                TreeNode* node=q.front();
                temp.push_back(node->val);
                q.pop();
                if(node->left!=NULL)
                q.push(node->left);
                if(node->right!=NULL)
                q.push(node->right);
            }
            if(flag==0)
            v.push_back(temp);
            else
            {
                reverse(temp.begin(),temp.end());
                v.push_back(temp);
            }
            flag=1-flag;
        }
        return v;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> v;
        if(root==NULL)
        return v;
        return v=helper(root);
    }
};