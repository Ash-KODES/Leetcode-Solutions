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
    int deepestLeavesSum(TreeNode* root) 
    {
        //BFS
        int ans=0;
        if(root==NULL)
        return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(true)
        {
            int sum=0;
            int loop=q.size();
            if(loop==0)
            break;
            while(loop--)
            {
                TreeNode* temp=q.front();
                sum+=temp->val;
                q.pop();
                if(temp->left!=NULL)
                q.push(temp->left);
                if(temp->right!=NULL)
                q.push(temp->right);
            }
            ans=sum;
        }
        return ans;
        
    }
};