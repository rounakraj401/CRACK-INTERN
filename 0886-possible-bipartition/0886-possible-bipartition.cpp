class Solution {
public:
    bool dfs(int node,vector<int>&color,vector<int>adj[])
    {
        if(color[node]==-1)
            color[node]=1;
        
        for(auto it:adj[node])
        {
            if(color[it]==-1)
            {
                color[it]=1-color[node];
                
                if(!dfs(it,color,adj))
                    return false;
            }
            else if(color[it]==color[node])
                return false;
        }
        return true;
    }
    bool possibleBipartition(int t, vector<vector<int>>& dis) {
        int n=dis.size();
        
        vector<int>adj[t+1];
        for(int i=0;i<n;i++)
        {
            adj[dis[i][0]].push_back(dis[i][1]);
            adj[dis[i][1]].push_back(dis[i][0]);
        }
        
        vector<int>color(t+1,-1);
        
        for(int i=1;i<=t;i++)
        {
            if(color[i]==-1)
            {
                if(!dfs(i,color,adj))
                    return false;
            }
        }
        return true;
    }
};