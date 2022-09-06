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
    int widthOfBinaryTree(TreeNode* root)
    {
        if(root==NULL)
        {
            //No tree is present
            return 0;
        }
        //(i)->2*i+1/2*i+2
        queue<pair<TreeNode*,long long int>> q;
        q.push({root,1});
        long long int max_width=1;
        while(true)
        {
            int loop=q.size();
            if(loop==0)
            break;
            pair<TreeNode*,long long int> leftmost=q.front();
            pair<TreeNode*,long long int> rightmost=q.back();
            max_width=max(max_width,rightmost.second-leftmost.second+1LL);
            while(loop--)
            {
                pair<TreeNode*,int> node=q.front();
                q.pop();
                if(node.first->left!=NULL)
                {
                    q.push({node.first->left,node.second*2LL+1LL});
                }
                if(node.first->right!=NULL)
                {
                    q.push({node.first->right,node.second*2LL+2LL});
                }
            }
        }
        return max_width;
        
    }
};