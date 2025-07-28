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
unordered_map<TreeNode*,int>mp;
    int rob(TreeNode* root) {
        if(root==NULL)
         return 0;

        if(mp.find(root)!=mp.end())
        return mp[root];

        mp[root]=-1;
        int robbed=root->val;
        int notrob=0;

        notrob=rob(root->left)+ rob(root->right);

        int x=0;
        int y=0;
        if(root->left!=NULL)
        {
            x=rob(root->left->left) + rob(root->left->right);
        }
        if(root->right!=NULL)
        {
            y=rob(root->right->left)+ rob(root->right->right);
        }
        robbed+=(x+y);

        return mp[root]=max(robbed, notrob);
    }
};