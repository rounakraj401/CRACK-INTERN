/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* node, unordered_map<Node*,Node*>&mp)
    {
        Node* cur= new Node(node->val);
        mp[node]=cur;
        
        for(auto neigh:node->neighbors)
        {
            if(mp.find(neigh)==mp.end())
            {
                dfs(neigh,mp);
            }
            cur->neighbors.push_back(mp[neigh]);
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL)return NULL;
        
        unordered_map<Node*,Node*> mp; 
        dfs(node,mp);
        return mp[node];
    }
};