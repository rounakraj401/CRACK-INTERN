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
    void inorder(TreeNode* root,set<int>&st,int level,int &ans)
    {
        if(root==NULL)return;
        
        if(st.find(level)==st.end())
        {
            ans=root->val;
            st.insert(level);
        }
        inorder(root->left,st,level+1,ans);
        inorder(root->right,st,level+1,ans);
        return;
    }
    int findBottomLeftValue(TreeNode* root) {
        set<int>st;
        int ans=-1;
        inorder(root,st,0,ans);
        
        return ans;
    }
};