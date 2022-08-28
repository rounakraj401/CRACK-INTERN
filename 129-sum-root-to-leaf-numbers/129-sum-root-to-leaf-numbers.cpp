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
    void findallPaths(TreeNode* root,vector<string>&allPaths,string temp)
    {
        if(root->left==NULL && root->right==NULL)
        {
            temp+=to_string(root->val);
            allPaths.push_back(temp);
            return;
        }
        
        temp+=to_string(root->val);
        if(root->left!=NULL)findallPaths(root->left,allPaths,temp);
        if(root->right!=NULL)findallPaths(root->right,allPaths,temp);
    }
    
    int sumNumbers(TreeNode* root) {
        if(root==NULL)return 0;
        vector<string>allPaths;
        findallPaths(root,allPaths,"");
        
        int n=allPaths.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=stoi(allPaths[i]);
        }
        return ans;
    }
};