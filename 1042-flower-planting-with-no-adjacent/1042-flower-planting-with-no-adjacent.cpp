class Solution {
public:
   void dfs(int node,vector<int>&ans,vector<int>adj[])
   {
       for(int i=1;i<=4;i++)
       {
           bool flag=0;
           for(auto it:adj[node])
           {
               if(ans[it]==i)
               {
                   flag=1;
                   break;
               }
           }
           
           if(flag==0)
           {
               ans[node]=i;
               break;
           }
       }
       for(auto it:adj[node])
       {
           if(ans[node]==-1)
               dfs(it,ans,adj);
       }
       return;
   }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int>ans(n+1,-1);
        vector<int>adj[n+1];
        for(auto it:paths)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        for(int i=1;i<=n;i++)
        {
            if(ans[i]==-1)
                dfs(i,ans,adj);
        }
        ans.erase(ans.begin());
        return ans;
    }
};