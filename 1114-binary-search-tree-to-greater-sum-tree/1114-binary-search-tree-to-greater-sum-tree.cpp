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
    void fun(TreeNode* root,int &cnt)
    {
        if(root==NULL)return;
        fun(root->right,cnt);
        
        root->val+=cnt;
        cnt=root->val;
        
        fun(root->left,cnt);
        return;
    }
    TreeNode* bstToGst(TreeNode* root) {
        int cnt=0;
        fun(root,cnt);
        return root;
    }
};