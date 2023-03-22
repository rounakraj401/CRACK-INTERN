class Solution {
public:
    void dfs(int i,vector<pair<int,int>>adj[] , vector<int>&vis,int &ans)
    {
        vis[i]=1;
        for(auto it:adj[i])
        {
            ans=min(ans,it.second);
        }
        for(auto it:adj[i])
        {
            if(!vis[it.first])
                dfs(it.first,adj,vis,ans);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {        
        vector<pair<int,int>>adj[n+1];
        int ans=INT_MAX;
        int x=roads.size();
        for(int i=0;i<x;i++)
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        vector<int>vis(n+1,0);
        dfs(1,adj,vis,ans);
        
        if(vis[1]==1 && vis[n]==1)return ans;
        return 0;
    }
};