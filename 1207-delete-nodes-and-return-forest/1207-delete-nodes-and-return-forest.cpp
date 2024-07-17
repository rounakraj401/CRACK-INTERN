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
    vector<TreeNode*>ans;
    TreeNode* fun(TreeNode* root,set<int>&st)
    {
        if(root==NULL)return NULL;
        
        root->left=fun(root->left,st);
        root->right=fun(root->right,st);
        
        if(st.count(root->val))
        {
            if(root->left!=NULL)
                ans.push_back(root->left);
            if(root->right!=NULL)
                ans.push_back(root->right);
            
            return NULL;
        }
        return root;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int>st;
        for(auto it:to_delete)st.insert(it);
        
        TreeNode* node=fun(root,st);
            if(node)
            {
                ans.push_back(node);
            }
        return ans;
    }
};