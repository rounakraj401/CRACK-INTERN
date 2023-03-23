class Solution {
public:
    void dfs(int node,vector<int>adj[],vector<int>&vis)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                dfs(it,adj,vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)return -1;
        
        vector<int>vis(n+1,0);
        vector<int>adj[n+1];
        for(auto it:connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        int comp=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
              comp++;
              dfs(i,adj,vis);   
            }
        }
        
        comp--;
        
        return comp;
        
    }
};