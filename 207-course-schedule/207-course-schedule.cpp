class Solution {
public:
    bool dfs(int node,vector<bool>&par,vector<int>&vis,vector<int>adj[])
    {
        vis[node]=1;
        par[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it,par,vis,adj))return true;
            }
            else if(par[it])return true;
        }
        par[node]=0;
        return false;
    }
    bool canFinish(int num, vector<vector<int>>& pre) {
        int n=pre.size();
        vector<int>adj[num];
        for(int i=0;i<n;i++)
        {
            adj[pre[i][0]].push_back(pre[i][1]);
        }
        vector<int>vis(num,0);
        vector<bool>par(num,0);
        
        for(int i=0;i<num;i++)
        {
            if(!vis[i])
                if(dfs(i,par,vis,adj))return false;
        }
        return true;
    }
};