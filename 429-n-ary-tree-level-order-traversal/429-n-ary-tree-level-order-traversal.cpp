/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;
        queue<Node*>pq;
        
        if(!root)return ans;
        pq.push(root);
        while(!pq.empty())
        {
            int size=pq.size();
            vector<int>vec;
            for(int i=0;i<size;i++)
            {
                Node* node=pq.front();
                vec.push_back(node->val);
                pq.pop();
                
                for(int k=0;k<node->children.size();k++)
                    pq.push(node->children[k]);
            }
            ans.push_back(vec);
        }
        return ans;
    }
};