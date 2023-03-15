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
    bool isCompleteTree(TreeNode* root) {
        if(root==NULL)return true;
        queue<TreeNode*>pq;
        pq.push(root);
        
        bool flag=0;
        
        while(pq.size()>0)
        {
            TreeNode* ff=pq.front();
            pq.pop();
            
            if(ff==NULL)flag=1;
            else
            {
                if(flag==1)return false;
                pq.push(ff->left);
                pq.push(ff->right);
            }  
        }
        return true;
    }
};