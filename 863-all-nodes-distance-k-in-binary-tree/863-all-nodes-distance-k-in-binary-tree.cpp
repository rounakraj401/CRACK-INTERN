/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void mark(TreeNode* root,unordered_map<TreeNode* ,TreeNode*>&parent)
    {
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* cur=q.front();
            q.pop();
            
            if(cur->left)
            {
                parent[cur->left]=cur;
                q.push(cur->left);
            }
            if(cur->right)
            {
                parent[cur->right]=cur;
                q.push(cur->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* ,TreeNode*>parent;
        mark(root,parent);
        
        int lvl=0;
        
        unordered_map<TreeNode*,bool>vis;
        queue<TreeNode*>q;
        
        q.push(target);
        vis[target]=1;
        
        while(!q.empty())
        {
            int size=q.size();
            
            if(lvl++==k)break;
            for(int i=0;i<size;i++)
            {
                TreeNode* cur=q.front();
                q.pop();
                
                if(cur->left && !vis[cur->left])
                {
                    q.push(cur->left);
                    vis[cur->left]=1;
                }
                if(cur->right && !vis[cur->right])
                {
                    q.push(cur->right);
                    vis[cur->right]=1;
                }
                if(parent[cur] && !vis[parent[cur]])
                {
                    q.push(parent[cur]);
                    vis[parent[cur]]=1;
                }
            }
        }
        vector<int>ans;
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};