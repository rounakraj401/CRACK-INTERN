class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pair<int,int>>> adj(N+1);
            for(int i=0;i<times.size();i++)
            {
                    adj[times[i][0]].push_back({times[i][1],times[i][2]});
            }
            
            
            
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
            set<int> visited_nodes;
            vector<int> distance(N+1,INT_MAX);
            distance[K]=0;
            pq.push({0,K});
           
            while(!pq.empty()){
                     
                    pair<int,int> cur=pq.top();
                    pq.pop();
                    int node=cur.second;
               
                    for(int i=0;i<adj[node].size();i++){
                            int n=adj[node][i].first;
                            int w=adj[node][i].second;
                            if(distance[n]>distance[node]+w)
                            {
                                    distance[n]=distance[node]+w;
                                   
                                    pq.push({distance[n],n});
                            }
                    }
                    
            }
            
            int ans=0;
            for(int i=1;i<N+1;i++){
                    
                    ans=max(ans,distance[i]);
            }
            
            
            return ans==INT_MAX?-1:ans;
            
        
    }
};