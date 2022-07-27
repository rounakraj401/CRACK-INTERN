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
    void fun(TreeNode* root,TreeNode* parent,int &moves)
    {
        if(!root)return ;
        
       fun(root->left,root,moves);
       fun(root->right,root,moves);
        
       if(root->val>=1)
       {
           int extra=(root->val)-1;
           parent->val+=extra;
           root->val=1;
           moves+=extra;
       }
        else
        {
            int need=1+abs(root->val);
            parent->val-=need;
            root->val=1;
            moves+=need;
        }
    }
    int distributeCoins(TreeNode* root) {
        
         int moves=0;
         fun(root,root,moves);
         return moves;
      
    }
};