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
    void fun(TreeNode* root,int &k,TreeNode *&prev)
    {
        if(root==NULL)return;
        
        fun(root->left,k,prev);
        
        k--;
        if(k==0)
        {
            prev=root;
            return;
        }
        
        fun(root->right,k,prev);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* prev=NULL;
        fun(root,k,prev);
        return prev->val;
    }
};