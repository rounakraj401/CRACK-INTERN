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
    int sumEvenGrandparent(TreeNode* root) {
        int ans=0;
        
        queue<TreeNode*>pq;
        pq.push(root);
        if(root->left)pq.push(root->left);
        if(root->right)pq.push(root->right);
            
        while(!pq.empty())
        {
            TreeNode* node=pq.front();
            pq.pop();
            
            if((node->val)%2==0)
            {
                if(node->left!=NULL && node->left->left!=NULL) ans+=(node->left->left)->val;
                if(node->left!=NULL && node->left->right!=NULL) ans+=(node->left->right)->val;
                if(node->right!=NULL && node->right->left!=NULL) ans+=(node->right->left)->val;
                if(node->right!=NULL && node->right->right!=NULL) ans+=(node->right->right)->val;
            }
            
                if(node->left!=NULL && node->left->left!=NULL) pq.push(node->left->left);
                if(node->left!=NULL && node->left->right!=NULL) pq.push(node->left->right);
                if(node->right!=NULL && node->right->left!=NULL) pq.push(node->right->left);
                if(node->right!=NULL && node->right->right!=NULL) pq.push(node->right->right);
        }
        return ans;
    }
};