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
    void fun(TreeNode* node,vector<int>&ans)
    {
        if(!node)return;
        ans.push_back(node->val);
        if(node->left)fun(node->left,ans);
        if(node->right)fun(node->right,ans);
        
        return;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
//         if(root==NULL)return ans;
        
//         stack<TreeNode*>st;
//         st.push(root);
        
//         while(!st.empty())
//         {
//             TreeNode *x=st.top();
//             root=st.top();
//             st.pop();
            
//             ans.push_back(root->val);
//             if(root->right!=NULL)st.push(root->right);
//             if(root->left!=NULL)st.push(root->left);
//         }
        fun(root,ans);
        return ans;
    }
};