class Solution {
public:
    bool dfs(int i,vector<int>&vis,vector<vector<int>>&adj,vector<int>&ans)
    {
        vis[i]=1;
        for(auto it:adj[i])
        {
            if(vis[it]==1)
                return false;
            if(vis[it]==0)
            {
                if(!dfs(it,vis,adj,ans))
                    return false;
            }
        }
        vis[i]=2;
        ans.push_back(i);
        return true;
    }
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        vector<int>ans;
        vector<vector<int>>adj(num);
        
        for(int i=0;i<pre.size();i++)
        {
            adj[pre[i][0]].push_back(pre[i][1]);
        }
        vector<int>vis(num,0);
        for(int i=0;i<num;i++)
        {
            if(vis[i]==0)
            {
                if(!dfs(i,vis,adj,ans))  // cycle detected
                {
                    ans.clear();
                    break;
                }
            }
        }
        return ans;
    }
};