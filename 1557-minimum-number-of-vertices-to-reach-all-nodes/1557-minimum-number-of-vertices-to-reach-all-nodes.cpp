class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>adj[n+1];
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
        }
        
        vector<int>ans;
        vector<int>vis(n+1,0);
        
        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i])
            {
                vis[it]=1;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i])ans.push_back(i);
        }
        return ans;
    }
};