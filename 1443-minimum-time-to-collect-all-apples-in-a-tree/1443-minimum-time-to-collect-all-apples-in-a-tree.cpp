class Solution {
public:    
//     int DFS(int node,int node_cost,vector<int>adj[],vector<bool>&vis,vector<bool>contains)
//     {
//         if(vis[node])
//             return 0;
        
//         vis[node]=1;
        
//         int child_cost=0;
//         for(auto it:adj[node])
//         {
//             child_cost+=DFS(it,2,adj,vis,contains);
//         }
//         if(child_cost==0 && contains[node]==0)
//             return 0;
        
//         return child_cost+node_cost;
//     }
//     int minTime(int n, vector<vector<int>>& edges, vector<bool>&contains) {
//         int m=edges.size();
//         vector<int>adj[n+1];
//         for(int i=0;i<m;i++)
//         {
//             adj[edges[i][0]].push_back(edges[i][1]);
//             adj[edges[i][1]].push_back(edges[i][1]);
//         }
        
//         vector<bool>vis(n+1,0);
//         return DFS(0,0,adj,vis,contains);
//     }
    
    void createGraph(vector<vector<int>>& edges, vector<int> adj[]) {
    for (auto e: edges) {
        adj[e[0]].push_back(e[1]); // adjecency list representation
        adj[e[1]].push_back(e[0]); // adjecency list representation
    }
}

int dfs(int node, int myCost, vector<bool>& hasApple, vector<int> adj[], vector<bool>& visited) {
    if (visited[node]) {
        return 0;
    }
    visited[node] = true;
    
    int childrenCost = 0; // cost of traversing all children. 
    for (auto x: adj[node]) { 
        childrenCost += dfs(x, 2, hasApple, adj, visited);  // check recursively for all apples.
    }

    if (childrenCost == 0 && hasApple[node] == false) {
    // If no child has apples, then we won't traverse the subtree, so cost will be zero.
    // similarly, if current node also does not have the apple, we won't traverse this branch at all, so cost will be zero.
        return 0;
    }
    
    // Children has at least one apple or the current node has an apple, so add those costs.
    return (childrenCost + myCost);
}

int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    vector<int> adj[n];     // to store the graph
    vector<bool> visited(n, false);     // to stop exploring same nodes again and again.
    createGraph(edges, adj); // construct the graph first.
    return dfs(0, 0, hasApple, adj, visited); // cost of reaching the root is 0. For all others, its 2.
}
};