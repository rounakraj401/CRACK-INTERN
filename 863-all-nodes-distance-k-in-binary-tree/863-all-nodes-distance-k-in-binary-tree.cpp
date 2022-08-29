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
    void markParent(TreeNode* root,TreeNode* parent,unordered_map<TreeNode*,TreeNode*>&mp)
    {
        if(root==NULL)return;
        mp[root]=parent;
        
        markParent(root->left,root,mp);
        markParent(root->right,root,mp);
        return;
    }
    
    void printKdistance(TreeNode* currnode,unordered_map<TreeNode*,TreeNode*>&mp,set<TreeNode*>&st,int k,vector<int>&ans)
    {
        if(currnode==NULL || st.find(currnode)!=st.end() || k<0)return;
        
        st.insert(currnode);
        
        if(k==0)
        {
            ans.push_back(currnode->val);
            return;
        }        
        printKdistance(currnode->left,mp,st,k-1,ans);
        printKdistance(currnode->right,mp,st,k-1,ans);
        printKdistance(mp[currnode],mp,st,k-1,ans);
        return;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*>mp;
        vector<int>ans;
        set<TreeNode*>st;
        
        markParent(root,NULL,mp);
        
        printKdistance(target,mp,st,k,ans);
        return ans;
    }
};