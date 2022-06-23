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
    int maxDepth(TreeNode* root) {
        if(root==NULL)return 0;
        if(root->left==NULL && root->right==NULL)
            return 1;
        
        int x=INT_MIN;
        int y=INT_MIN;
        if(root->left!=NULL)x=maxDepth(root->left);
        if(root->right!=NULL)y=maxDepth(root->right);
        
        return 1+max(x,y);
    }
};