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
    void preorder(TreeNode* node,vector<int>&pre)
    {
        if(node==NULL)return;
        pre.push_back(node->val);
        
        preorder(node->left,pre);
        preorder(node->right,pre);
    }
    void fun(TreeNode *node,unordered_map<int,int>&mp)
    {
        if(node==NULL)return;
        node->val=mp[node->val];
        
        fun(node->left,mp);
        fun(node->right,mp);
    }
    TreeNode* bstToGst(TreeNode* root) {
        vector<int>pre;
        preorder(root,pre);
        
        sort(pre.begin(),pre.end());
        int sum=accumulate(pre.begin(),pre.end(),0ll);
        
        unordered_map<int,int>mp;
        int x=0;
        for(int i=0;i<pre.size();i++)
        {
            mp[pre[i]]=sum-x;
            x+=pre[i];
        }
        
        fun(root,mp);
        return root;
    }
};