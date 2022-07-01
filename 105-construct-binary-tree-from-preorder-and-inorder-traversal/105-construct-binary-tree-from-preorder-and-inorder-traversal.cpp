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
    TreeNode* create(vector<int>& preorder, vector<int>& inorder, unordered_map<int,int>&mp,int ps,int pe,int is,int ie)
    {
        if(ps>pe || is>ie)
            return nullptr;
        int rootIndxInInorder=mp[preorder[ps]];
        int lps=ps+1;
        int lpe=ps+rootIndxInInorder-is;
        int rps=lpe+1;
        int rpe=pe;
        int lis=is;
        int lie=rootIndxInInorder-1;
        int ris=rootIndxInInorder+1;
        int rie=ie;
        TreeNode* root=new TreeNode(preorder[ps]);
        TreeNode* left=create(preorder,inorder,mp,lps,lpe,lis,lie);
        TreeNode* right=create(preorder,inorder,mp,rps,rpe,ris,rie);
        root->left=left;
        root->right=right;
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
          int n=preorder.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
            mp[inorder[i]]=i;
        return create(preorder,inorder,mp,0,n-1,0,n-1);
    }
};