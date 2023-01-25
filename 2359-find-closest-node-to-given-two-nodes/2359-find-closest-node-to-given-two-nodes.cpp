class Solution {
public:
    void bfs(int src , vector<int>&edges , vector<int>&dist)
    {
        queue<int>pq;
        pq.push(src);
        dist[src]=0;
        
        while(!pq.empty())
        {
            int node=pq.front();
            pq.pop();
            
            if(edges[node]!=-1 && dist[edges[node]]==INT_MAX)
            {
                pq.push(edges[node]);
                dist[edges[node]]=dist[node]+1;
            }
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int>dist1(n,INT_MAX),dist2(n,INT_MAX);
        bfs(node1,edges,dist1);
        bfs(node2,edges,dist2);
        
        int ans=INT_MAX;
        int node=-1;
        
        for(int i=0;i<n;i++)
        {
            if(dist1[i]!=INT_MAX && dist2[i]!=INT_MAX)
            {
                if(ans>max(dist1[i],dist2[i]))
                {
                    node=i;
                    ans=max(dist1[i],dist2[i]);
                }
            }
        }
        return node;
    }
};