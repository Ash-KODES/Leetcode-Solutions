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
    TreeNode* helper(vector<int>& postorder, vector<int>& inorder,int& index,int start,int end)
    {
        //Base cases
        if(start>end||index<0)
        return NULL;
        TreeNode* root=new TreeNode(postorder[index]);
        int pos=0;
        for(auto i=0;i<inorder.size();i++)
        {
            if(inorder[i]==(root->val))
            {
                pos=i;
                break;
            }
        }
        index--;
        root->right=helper(postorder,inorder,index,pos+1,end);
        root->left=helper(postorder,inorder,index,start,pos-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //Postorder-> left right root
        //inorder  -> left root right
        int index=postorder.size()-1;
        return helper(postorder,inorder,index,0,inorder.size()-1);
    }
};