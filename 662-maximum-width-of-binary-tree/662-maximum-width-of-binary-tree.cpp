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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        int ans=0;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        
        while(!q.empty())
        {
            int size=q.size();
            int minm=q.front().second;
            int f,l;
            for(int i=0;i<size;i++)
            {
                long long cur=q.front().second-minm;
                TreeNode* node=q.front().first;
                q.pop();
                
                if(i==0)f=cur;
                if(i==size-1)l=cur;
                
                if(node->left)q.push({node->left,2*cur+1});
                if(node->right)q.push({node->right,2*cur+2});
            }
            ans=max(ans,l-f+1);
        }
        return ans;
    }
};