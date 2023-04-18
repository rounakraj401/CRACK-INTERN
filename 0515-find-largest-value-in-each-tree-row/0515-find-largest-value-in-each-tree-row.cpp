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
    vector<int> largestValues(TreeNode* root) {
        vector<int>vec;
        if(root==NULL)return vec;
        
        queue<TreeNode*>pq;
        pq.push(root);
        
        while(!pq.empty())
        {
            int sz=pq.size();
            int ans=INT_MIN;
            
            while(sz--)
            {
                TreeNode* node=pq.front();
                pq.pop();
                ans=max(ans,node->val);
                
                if(node->left)pq.push(node->left);
                if(node->right)pq.push(node->right);
            }
            vec.push_back(ans);
        }
        return vec;
    }
};