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
    TreeNode* getTargetCopy(TreeNode* orig, TreeNode* clone, TreeNode* targ) {
        if(orig==NULL)
            return NULL;
        if(orig==targ)
            return clone;
        auto x=getTargetCopy(orig->left,clone->left,targ);
        if(x)
            return x;
        return getTargetCopy(orig->right,clone->right,targ);
    }
};