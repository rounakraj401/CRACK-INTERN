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
    const int mod=1e9+7;
    int getsum(TreeNode* root)
    {
        if(!root)return 0;
        root->val+=(getsum(root->right)+getsum(root->left));
        return root->val;
    }
    int maxProduct(TreeNode* root) {
        
        long long int sum=getsum(root);
        
        queue<TreeNode*>q;
        q.push(root);
        long long int ans=0;
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            
            ans=max(ans,node->val*(sum-node->val));
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
        return ans%mod;
    }
};