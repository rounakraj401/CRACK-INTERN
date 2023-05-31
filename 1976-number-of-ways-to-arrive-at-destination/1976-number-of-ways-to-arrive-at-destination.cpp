class Solution {
public:
    int fun(vector<pair<int,int>>adj[], int n)
    {
         int mod=1e9+7;
        priority_queue<pair<long long int,long long int>,vector<pair<long long int,long long int>>,greater<pair<long long int,long long int>> >pq;
        vector<long long int>path(n+1,0);
        vector<long long int>dis(n+1,1e15);
        
        pq.push({0,0});
        dis[0]=0;
        path[0]=1;
        
        while(!pq.empty())
        {
            long long int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto &child:adj[node])
            {
                int adjNode = child.first;
                long long wt = child.second;

                if (dist + wt < dis[adjNode]) {
                    dis[adjNode] = dist + wt;
                    path[adjNode] = path[node];
                    pq.push({dist + wt, adjNode});
                }
                else if (dist + wt == dis[adjNode]) {
                    path[adjNode] = (path[node] + path[adjNode]) % mod;
                }
            }
        }
        return path[n-1];
        
        
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n+1];
        int x=roads.size();
        
        for(int i=0;i<x;i++)
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        
        return fun(adj,n);
    }
};