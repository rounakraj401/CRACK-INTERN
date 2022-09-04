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
    
    void fun(TreeNode* cur,vector<int>&ans)
    {
        if(!cur)return;
        fun(cur->left,ans);
        fun(cur->right,ans);
        
        ans.push_back(cur->val);
        return;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        
//         vector<int>ans;
//         stack<TreeNode*>st1;
//         stack<TreeNode*>st2;
        
//         if(root==NULL)return ans;
        
//         st1.push(root);
//         while(!st1.empty())
//         {
//             TreeNode *x=st1.top();
//             st1.pop();
            
//             st2.push(x);
            
//             if(x->left!=NULL)st1.push(x->left);
//             if(x->right!=NULL)st1.push(x->right);    
//         }
//         while(!st2.empty())
//         {
//             ans.push_back(st2.top()->val);
//             st2.pop();
//         }
//         return ans;
        
         vector<int>ans;
         stack<TreeNode*>st;
         TreeNode* cur=root;
        
        if(cur==NULL)return ans;
        
//         while(cur!=NULL ||!st.empty() )
//         {
//             if(cur!=NULL)
//             {
//                 st.push(cur);
//                 cur=cur->left;
//             }
//             else
//             {
//                 TreeNode* temp=st.top()->right;
                
//                 if(temp==NULL)
//                 {
//                     temp=st.top();
//                     st.pop();
//                     ans.push_back(temp->val);
//                     while(!st.empty() && temp==st.top()->right)
//                     {
//                         temp=st.top();
//                         st.pop();
//                         ans.push_back(temp->val);
//                     }
//                 }
//                 else
//                     cur=temp;
//             }
        fun(cur,ans);
        return ans;
        
        
    }
};