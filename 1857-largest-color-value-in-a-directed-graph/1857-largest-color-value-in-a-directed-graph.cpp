class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int x=colors.size();
        queue<int>q;
        vector<vector<int>>adj(x);
        vector<int>indegree(x,0);
        vector<vector<int>>count(x,vector<int>(26,0));
        
        for(auto e:edges)
        {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        
        int ans=0;
        int total=0;
        
        for(int i=0;i<x;i++){
            if(indegree[i]==0)q.push(i);
        }
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            total++;
            ans=max(ans, ++count[node][colors[node]-'a']);
            
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
                
                for(int c=0;c<26;c++)
                {
                    count[it][c]=max(count[it][c] , count[node][c]);
                }
            }
        }
        if(total!=x)return -1;
        return ans;
    }
};