class Solution {
public:
    void countchild(int node,vector<int>adj[],vector<int>&child)
    {
        child[node]=1;
        for(auto it:adj[node])
        {
            if(child[it]==0)
            {
                countchild(it,adj,child);
                child[node]+=child[it];
            }
        }
        return;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size();
        
        vector<int>adj[n+1];
        for(auto it:roads)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>child(n+1,0);
        countchild(0,adj,child);
        
        vector<int>vis(n+1,-1);
        
        queue<int>pq;
        pq.push(0);
        vis[0]=1;
        
        long long ans=0;
        
        while(!pq.empty())
        {
            int node=pq.front();
            pq.pop();
            
            for(auto it:adj[node])
            {
                if(vis[it]!=-1)
                    continue;
                
                ans+=child[it]/seats;
                if(child[it]%seats)ans++;
                
                vis[it]=1;
                pq.push(it);
            }
        }
        return ans;
    }
};