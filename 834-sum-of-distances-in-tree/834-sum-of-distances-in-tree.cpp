class Solution {
public:
    vector<int>dep;
    vector<int>sub;
    vector<int>sum;
    void dfs(int u,vector<int>adj[],int par=-1)
    {
        sub[u]=1;
        for(auto it:adj[u])
        {
            if(it==par)continue;
            
            dep[it]=dep[u]+1;
            dfs(it,adj,u);
            sub[u]+=sub[it];
        }
    }
    void dfs2(int u,vector<int>adj[],int n,int par=-1)
    {
        for(auto it:adj[u])
        {
            if(it==par)continue;
            
            sum[it]=sum[u]-sub[it]+(n-sub[it]);
            dfs2(it,adj,n,u);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dep.resize(n+1);
        sub.resize(n+1);
        sum.resize(n);
        
        dfs(0,adj);
        for(int i=0;i<n;i++)sum[0]+=dep[i];
        
        dfs2(0,adj,n);
        return sum;
    }
};