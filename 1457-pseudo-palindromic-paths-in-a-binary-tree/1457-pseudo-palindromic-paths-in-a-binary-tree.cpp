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
    void fun(TreeNode* root,set<int>st,int &ans)
    {
        if(st.find(root->val)!=st.end())st.erase(root->val);
        else
            st.insert(root->val);
        
        if(!root->left && !root->right)
        {
            if(st.size()<=1)ans++;
            return;
        }
        
        if(root->left)fun(root->left,st,ans);
        if(root->right)fun(root->right,st,ans);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        set<int>st;
        int ans=0;
        if(!root)return ans;
        fun(root,st,ans);
        
        return ans;
    }
};