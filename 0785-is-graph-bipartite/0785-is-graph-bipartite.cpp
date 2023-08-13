class Solution {
public:
    bool dfs(int node,int col,vector<int>&color,vector<int>adj[])
    {
        color[node]=col;
        
        for(auto it:adj[node])
        {
            if(color[it]==-1)
            {
                if(dfs(it,!col,color,adj)==false)
                    return false;
            }
            else if(color[it]==col)
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>adj[n+1];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                adj[i].push_back(graph[i][j]);
                adj[graph[i][j]].push_back(i);
            }
        }
        
        vector<int>color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(dfs(i,0,color,adj)==false)
                    return false;
            }
        }
        return true;
    }
};