class Solution {
public:
    void DFS(int node,int par,vector<int>adj[],string &labels,vector<int>&ans,vector<vector<int>>&dp)
    {
        dp[node][labels[node]-'a']++;
        
        for(auto it:adj[node])
        {
            if(it!=par)
            {
                DFS(it,node,adj,labels,ans,dp);
                for(int k=0;k<27;k++)
                {
                    dp[node][k]+=dp[it][k];
                }
            }
        }
        ans[node]=dp[node][labels[node]-'a'];
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int>adj[n];
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<vector<int>>dp(n,vector<int>(27,0));
        vector<int>ans(n);
        
        DFS(0,-1,adj,labels,ans,dp);
        return ans;
    }
};