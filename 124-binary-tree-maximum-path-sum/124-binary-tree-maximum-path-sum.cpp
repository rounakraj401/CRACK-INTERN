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
    int maxsum(TreeNode* root,int &ans)
    {
        if(!root)return 0;
        
        int lh=max(0,maxsum(root->left,ans));
        int rh=max(0,maxsum(root->right,ans));
        
        ans=max(ans,lh+rh+root->val);
        
        return max(lh,rh)+root->val; 
    }
    int maxPathSum(TreeNode* root) {
        int ans=root->val;
        maxsum(root,ans);
        return ans;
    }
};