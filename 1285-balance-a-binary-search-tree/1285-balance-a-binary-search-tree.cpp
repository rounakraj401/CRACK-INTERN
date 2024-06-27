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
    void fun(vector<int>&inorder,TreeNode* node)
    {
         if(node==NULL)return;

         if(node->left)fun(inorder,node->left);
         inorder.push_back(node->val);
         if(node->right)fun(inorder,node->right);
    }

    TreeNode* balance(int left,int right,vector<int>&inorder)
    {
        if(left>right)return NULL;

        int mid=(left+right)/2;

        TreeNode* leftnode=balance(left,mid-1,inorder);
        TreeNode* rightnode=balance(mid+1,right,inorder);

        return new TreeNode(inorder[mid],leftnode,rightnode);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorder;
        fun(inorder,root);
        
        return balance(0,inorder.size()-1,inorder);
    }
};