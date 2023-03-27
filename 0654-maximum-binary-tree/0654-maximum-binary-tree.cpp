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
    TreeNode* helper(int start,int end,vector<int>&nums)
    {
        if(start>end)return NULL;
        
        int idx=-1;
        int maxm=-1;
        
        for(int i=start;i<=end;i++)
        {
            if(nums[i]>maxm)
            {
                idx=i;
                maxm=nums[i];
            }
        }
        
        TreeNode* root=new TreeNode(maxm);
        root->left=helper(start,idx-1,nums);
        root->right=helper(idx+1,end,nums);
        
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n=nums.size();
        return helper(0,n-1,nums);
    }
};