class Solution {
public:
    #define ll long long
    void dfs(ll i, vector<vector<ll>>&adj, vector<bool>&vis,ll &temp)
    {
        vis[i]=1;
        temp++;
        for(auto it :adj[i])
        {
            if(!vis[it])
                dfs(it,adj,vis,temp);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<ll>>adj(n,vector<ll>());
        ll m=edges.size();
        
        for(int i=0;i<m;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        
         ll ans=0;
         ll sum=0;
        vector<bool>vis(n,0);
        

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                ll temp=0;
                dfs(i,adj,vis,temp);
                ans+=(sum*temp);
                sum+=temp;
            }
        }
        return ans;
    }
};