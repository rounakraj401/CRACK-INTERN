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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        
        queue<TreeNode*>q;
        q.push(root);
        bool flag=1;
        
        while(!q.empty())
        {
            int size=q.size();
            vector<int>temp(size);
            
            for(int i=0;i<size;i++)
            {
                TreeNode* x= q.front();
                q.pop();
                
                int idx=(flag)? i:(size-1-i);
                
                temp[idx]=x->val;
                if(x->left)q.push(x->left);
                if(x->right)q.push(x->right);
                
            }
            flag=!flag;
            ans.push_back(temp);
        }
        return ans;
    }
};