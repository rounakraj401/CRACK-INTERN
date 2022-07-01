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
    TreeNode* create(vector<int>& postorder, vector<int>& inorder, unordered_map<int,int>&mp,int ps,int pe,int is,int ie)
    {
        if(ps>pe || is>ie)
            return nullptr;
        int rootIndxInInorder=mp[postorder[pe]];
        int lps=ps;
        int lpe=ps+rootIndxInInorder-is-1;
        int rps=lpe+1;
        int rpe=pe-1;
        int lis=is;
        int lie=rootIndxInInorder-1;
        int ris=rootIndxInInorder+1;
        int rie=ie;
        TreeNode* root=new TreeNode(postorder[pe]);
        TreeNode* left=create(postorder,inorder,mp,lps,lpe,lis,lie);
        TreeNode* right=create(postorder,inorder,mp,rps,rpe,ris,rie);
        root->left=left;
        root->right=right;
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)m[inorder[i]]=i;
        return create(postorder,inorder,m,0,n-1,0,n-1);
    }
};