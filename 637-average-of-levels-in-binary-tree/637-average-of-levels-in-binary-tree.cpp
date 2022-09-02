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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*>pq;
        vector<double>ans;
        
        pq.push(root);
        
        while(!pq.empty())
        {
            int size=pq.size();
            double sum=0;
            for(int i=0;i<size;i++)
            {
                TreeNode* node=pq.front();
                pq.pop();
                sum+=node->val;
                
                if(node->left)pq.push(node->left);
                if(node->right)pq.push(node->right);
            }
            ans.push_back(sum/(double)size);
        }
        return ans;
    }
};