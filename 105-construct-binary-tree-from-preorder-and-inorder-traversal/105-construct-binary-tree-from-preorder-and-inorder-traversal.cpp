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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int& index,int start,int end)
    {
        //Base cases
        if(start>end||index>=preorder.size())
        return NULL;
        TreeNode* root=new TreeNode(preorder[index]);
        int pos=0;
        for(auto i=0;i<inorder.size();i++)
        {
            if(inorder[i]==preorder[index])
            {
                pos=i;
                break;
            }
        }
        index++;
        root->left=helper(preorder,inorder,index,start,pos-1);
        root->right=helper(preorder,inorder,index,pos+1,end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        //Preorder ->root left right
        //inorder  ->left root right
        int index=0;
        return helper(preorder,inorder,index,0,preorder.size()-1);
    }
};