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
class BSTIterator {
public:
    stack<TreeNode*>st;
    bool rev=true;
    
    void pushh(TreeNode* root)
    {
        for(;root!=NULL;)
        {
            if(rev==true)
            {
                st.push(root);
                root=root->right;
            }
            else
            {
                st.push(root);
                root=root->left;
            }
        }
    }
    
    BSTIterator(TreeNode* root,bool flag) {
        rev=flag;
        pushh(root);
    }
    
    int next() {
        TreeNode *temp=st.top();
        st.pop();
        if(!rev)pushh(temp->right);  //rev=false->next
        else
            pushh(temp->left);       // rev=true->before
        
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)return false;
        
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        
        int i=l.next();
        int j=r.next();
        
        while(i<j)
        {
            if(i+j==k)return true;
            else if(i+j>k)j=r.next();
            else
                i=l.next();
            
        }
        return false;
        
    }
};