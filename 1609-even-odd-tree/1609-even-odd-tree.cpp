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
    bool isEvenOddTree(TreeNode* root) {
        
        queue<TreeNode*>pq;
        pq.push(root);
        
        int level=0;
        
        while(!pq.empty())
        {
            int sz=pq.size();
            bool inc=0;
            if(level%2==0)inc=1;
            
            int prev=-1;
            int maxm=INT_MAX;
            
            while(sz--)
            {
                TreeNode* node=pq.front();
                pq.pop();
                
                if(inc)
                {
                    if(node->val%2==0 || node->val<=prev)
                        return false;
                    else
                        prev=node->val;
                }
                else
                {
                    if(node->val%2==1 || node->val>=maxm)
                        return false;
                    else
                        maxm=node->val;
                }
                
                if(node->left!=NULL)pq.push(node->left);
                if(node->right!=NULL)pq.push(node->right);
            }
            
            level++;
        }
        return true;
    }
};