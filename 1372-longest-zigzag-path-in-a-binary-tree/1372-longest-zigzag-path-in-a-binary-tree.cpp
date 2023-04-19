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
    int ans=0;
    void fun(TreeNode* node,int score,int dir)
    {
        if(node==NULL)return;
        ans=max(ans,score);
        
        if(dir==0)
        {
            fun(node->right,score+1,1);
            fun(node->left,1,0);
        }
        else
        {
            fun(node->left,score+1,0);
            fun(node->right,1,1);
        }
        return;
    }
    int longestZigZag(TreeNode* root) {
        fun(root->left,1,0);
        fun(root->right,1,1);
        
        return ans;
    }
};