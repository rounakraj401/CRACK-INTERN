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
    void fun(TreeNode* root,int curmax,int &cnt)
    {
        if(!root)return;
        
        if(root->val>=curmax)
        {
            cnt++;
            curmax=root->val;
        }
        
        fun(root->left,curmax,cnt);
        fun(root->right,curmax,cnt);
        return;
    }
    int goodNodes(TreeNode* root) {
        int curmax=INT_MIN;
        int cnt=0;
        fun(root,curmax,cnt);
        
        return cnt;
    }
};