class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto it:flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        vector<int>dist(n,1e9);
        dist[src]=0;
        queue<pair<int , pair<int,int>> >q;
        q.push({0,{src,0}});
        
        while(!q.empty())
        {
            auto iter=q.front();
            
            int stops=iter.first;
            int node=iter.second.first;
            int dis=iter.second.second;
            q.pop();
            
            if(stops>k)continue;
            
            for(auto it:adj[node])
            {
                int adjNode=it.first;
                int edgeWeight=it.second;
                
                if(dist[adjNode]>dis+edgeWeight && stops<=k)
                {
                    dist[adjNode]=dis+edgeWeight;
                    q.push({stops+1,{adjNode,dis+edgeWeight}});
                }
            }
        }
        if(dist[dst]==1e9)return -1;
        return dist[dst];
    }
};