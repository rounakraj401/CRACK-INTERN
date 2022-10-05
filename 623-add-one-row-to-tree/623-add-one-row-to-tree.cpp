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
    void storeAll(TreeNode* start,int dep,priority_queue<pair<TreeNode*,int>>&pq)
    {
        if(start==NULL)return;
        
        pq.push({start,dep});
        storeAll(start->left,dep+1,pq);
        storeAll(start->right,dep+1,pq);
        return;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        priority_queue<pair<TreeNode* ,int>>pq;
        TreeNode* start=root;
        if(depth==1)
        {
            root=new TreeNode(val);
            root->left=start;
        }
        
        storeAll(start,1,pq);
        
        while(!pq.empty())
        {
            TreeNode* node=pq.top().first;
            int dep=pq.top().second;
            
            pq.pop();
            
            if(dep==depth-1)
            {
                TreeNode* n1=node->left;
                TreeNode* n2=node->right;
                
                node->left=new TreeNode(val);
                node->right=new TreeNode(val);
                
                node->left->left=n1;
                node->right->right=n2;
            }
        }
        
        return root;
    }
};