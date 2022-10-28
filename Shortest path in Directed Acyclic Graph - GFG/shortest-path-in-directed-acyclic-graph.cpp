//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        vector<pair<int,int>>adj[n];
        for(auto it:edges)
        {
            adj[it[0]].push_back({it[2],it[1]});
        }
        
        vector<int>dist(n,INT_MAX);
        
        dist[0]=0;
       priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> >pq;
        
        pq.push({0,0});
        
        while(!pq.empty())
        {
            int node=pq.top().second;
            int nodedis=pq.top().first;
            pq.pop();
            
            for(auto it:adj[node])
            {
                int adjnode=it.second;
                int adjdist=it.first;
                
                if(dist[adjnode]>nodedis+adjdist)
                {
                   dist[adjnode]=nodedis+adjdist;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        
        for(int i=0;i<n+1;i++)
        {
            if(dist[i]==INT_MAX)
              dist[i]=-1;
        }
        
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends