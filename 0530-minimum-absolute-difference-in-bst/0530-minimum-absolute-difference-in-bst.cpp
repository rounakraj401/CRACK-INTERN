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
        
        fun(inorder,node->left);
        inorder.push_back(node->val);
        fun(inorder,node->right);
        return;
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int>inorder;
        fun(inorder,root);
        
        int ans=INT_MAX;
        for(int i=0;i<inorder.size()-1;i++)
            ans=min(ans,abs(inorder[i]-inorder[i+1]));
        return ans;
    }
};