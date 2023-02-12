/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void storeparent(TreeNode* root,TreeNode* parent,unordered_map<TreeNode*,TreeNode*>&mp)
    {
        if(root==NULL)return;
        
        mp[root]=parent;
        storeparent(root->left,root,mp);
        storeparent(root->right,root,mp);
        
        return;
    }
    
    void fun(TreeNode* target , unordered_map<TreeNode* , TreeNode*>&mp,vector<int>&ans, int k,set<TreeNode*>&st)
    {
        if(k<0 || target==NULL || st.count(target))return;
        
        st.insert(target);
        
        if(k==0)
        {
            ans.push_back(target->val);
            return;
        }
        
        fun(target->left,mp,ans,k-1,st);
        fun(target->right,mp,ans,k-1,st);
        fun(mp[target],mp,ans,k-1,st);
        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>mp;
        storeparent(root,NULL,mp);
        
        vector<int>ans;
        set<TreeNode*>st;
        
        fun(target,mp,ans,k,st);
        return ans;
    }
};