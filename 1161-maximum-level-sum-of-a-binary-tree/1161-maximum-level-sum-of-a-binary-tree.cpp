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
    int maxLevelSum(TreeNode* root) {
        int sum=0,temp=INT_MIN;
        int level=0,ans=0;
        
        queue<TreeNode*>pq;
        pq.push(root);
        
        while(!pq.empty())
        {
            sum=0;
            level++;
            int sz=pq.size();
            while(sz--)
            {
                TreeNode* node=pq.front();
                pq.pop();
                
                sum+=node->val;
                if(node->left!=NULL)pq.push(node->left);
                if(node->right!=NULL)pq.push(node->right);
                
            }
 //           cout<<sum<<"\n";
            
            if(sum>temp)
            {
                temp=sum;
                ans=level;
            }
 //           cout<<temp<<" "<<ans<<"\n";
        }
        return ans;
    }
};