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
    unordered_map<int,int> markIndex(vector<int>&inorder)
    {
        unordered_map<int,int>mp;
        int n=inorder.size();
        for(int i=0;i<n;i++)
          mp[inorder[i]]=i;
        
        return mp;
    }
    TreeNode* constructTree(int start,int end,int &preidx,vector<int>&preorder,unordered_map<int,int>&mp)
    {
        if(start>end)return NULL;
        
        TreeNode* node= new TreeNode(preorder[preidx]);        
        int inidx=mp[preorder[preidx]];
        
        preidx++;
        
        node->left=constructTree(start,inidx-1,preidx,preorder,mp);
        node->right=constructTree(inidx+1,end,preidx,preorder,mp);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        
        unordered_map<int,int>mp=markIndex(inorder);
        int preidx=0;
        return constructTree(0,n-1,preidx,preorder,mp);
    }
};