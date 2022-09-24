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
    void fun(TreeNode* node,int sum,vector<int>&cur_path,vector<vector<int>>&ans)
    {
        if(!node)return;
        
        cur_path.push_back(node->val);
        
        if(node->left==NULL && node->right==NULL && node->val==sum)
            ans.push_back(cur_path);
        
        fun(node->left,sum-node->val,cur_path,ans);
        fun(node->right,sum-node->val,cur_path,ans);
        
        cur_path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>>ans;
        vector<int>cur_path;
        
        fun(root,sum,cur_path,ans);
        return ans;
    }
};