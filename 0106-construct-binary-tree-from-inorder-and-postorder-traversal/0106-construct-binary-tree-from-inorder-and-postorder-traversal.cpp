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
    TreeNode* create(vector<int>& postorder, vector<int>& inorder, unordered_map<int,int>&mp,int start,int end,int &idx)
    {
        if(start>end)return NULL;
        
        TreeNode* root= new TreeNode(postorder[idx]);
        
        int i=mp[root->val];
        
        idx--;
        
        root->right=create(postorder,inorder,mp,i+1,end,idx);
        root->left=create(postorder,inorder,mp,start,i-1,idx);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)m[inorder[i]]=i;
        int idx=n-1;
        
        return create(postorder,inorder,m,0,n-1,idx);
    }
};