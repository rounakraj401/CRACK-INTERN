class Solution {
public:
    bool check(vector<int>adj[],int node,vector<int>&color,int curr_color)
    {
        color[node]=curr_color;
        queue<int>pq;
        pq.push(node);
        
        while(!pq.empty())
        {
            int node=pq.front();
            pq.pop();
            
            for(auto it:adj[node])
            {
                if(color[it]==0)
                {
                 color[it]=-1*color[node];
                 pq.push(it);
                }
                else if(color[it]==color[node])
                {
                    return false;
                }
            }
            curr_color*=-1;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,0);
        vector<int>adj[n+1];
        for(int i=0;i<graph.size();i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                adj[i].push_back(graph[i][j]);
                adj[graph[i][j]].push_back(i);
            }
        }
        
        bool ans=true;
        for(int i=0;i<n;i++)
        {
            if(color[i]==0)
            {
                ans=ans && check(adj,i,color,1);
                if(!ans)
                    return false;
            }
        }
        return true;
    }
};