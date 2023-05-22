class Solution {
public:
    
    void dfs(int i,vector<int>&vis,vector<int>adj[],vector<int>&temp)
    {
        vis[i]=1;
        temp.push_back(i);
        for(auto it:adj[i])
        {
            if(!vis[it])
            {
                dfs(it,vis,adj,temp);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>adj[n+1];
        
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n+1,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                vector<int>temp;
                dfs(i,vis,adj,temp);
                
                bool flag=0;
                for(int j=0;j<temp.size();j++)
                {
                    if(adj[temp[j]].size()!=temp.size()-1)
                    {
                        flag=1;
                        break;
                    }
                }
                if(!flag)ans++;
            }            
        }
        return ans;
    }
};