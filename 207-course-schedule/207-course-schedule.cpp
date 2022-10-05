class Solution {
public:
    bool checkCycle(int i,vector<int>adj[] , vector<bool>&vis, vector<bool>&dfsvis)
    {
        vis[i]=1;
        dfsvis[i]=1;
        
        for(auto it:adj[i])
        {
            if(!vis[it])
            {
                if(checkCycle(it,adj,vis,dfsvis))
                    return true;
            }
            else if(dfsvis[it])
                return true;
        }
        dfsvis[i]=0;
        return false;
    }
    
    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<int>adj[num];
        int n=pre.size();
        for(int i=0;i<n;i++)
        {
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        vector<bool>vis(num+1,0);
        vector<bool>dfsvis(num+1,0);
        
        for(int i=0;i<num;i++)
        {
            if(!vis[i])
            {
                if(checkCycle(i,adj,vis,dfsvis))
                    return false;
            }
        }
        return true;
    }
};