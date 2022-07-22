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
    int a=0,b=0;
    int count(TreeNode* root)   // count nodes in a subtree.
    {
        if(!root)return 0;
        return (1+count(root->left)+count(root->right));
    }
    void find(TreeNode* root,int x)
    {
        if(!root)return;
        if(root->val==x)    // finding node with value 'x'.
        {
            a=count(root->left);     //counting left childs
            b=count(root->right);    //counting right childs
        }
        find(root->left,x);
        find(root->right,x);
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        find(root,x);
        int c=n-(a+b+1);   //counting remaning nodes
        
        if(c>n/2 || a>n/2 || b>n/2)return 1;   // c>n/2 is wrong because if n==11
        return 0;                              // any of the counts(a,b,c) should be atleast (n/2)+1;
    }
};