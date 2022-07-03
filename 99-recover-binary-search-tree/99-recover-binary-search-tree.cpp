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
    int i=0;
    void check(TreeNode* root,vector<int>&inn){
        if(!root) return;
        check(root->left,inn);
        if(inn[i]!=root->val) swap(inn[i],root->val);
        i++;
        check(root->right,inn);
    }
    
    void recoverTree(TreeNode* root) {
        vector<int>inn;
        stack<TreeNode*>st;
        TreeNode *node=root;
        while(1)
        {
            if(node!=NULL)
            {
                st.push(node);
                node=node->left;
            }
            else
            {
                if(st.empty())break;
                else
                {
                    node =st.top();
                    st.pop();
                    inn.push_back(node->val);
                    node=node->right;
                }
            }
        }
        sort(inn.begin(),inn.end());
        
        check(root,inn);
    }
};