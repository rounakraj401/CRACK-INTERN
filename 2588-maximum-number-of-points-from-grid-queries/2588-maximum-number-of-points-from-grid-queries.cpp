class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n=grid.size();
        int m=grid[0].size();
        
        
        vector<pair<int,int>>vec;
        for(int i=0;i<queries.size();i++)
            vec.push_back({queries[i],i});
        
        sort(vec.begin(),vec.end());
        
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        
        priority_queue<tuple<int,int,int> , vector<tuple<int,int,int>> , greater<tuple<int,int,int>> >pq;
        pq.push({grid[0][0],0,0});
        vis[0][0]=1;
        
        vector<int>ans(queries.size());
        int cnt=0;
        
        for(auto it:vec)
        {
            int qr=it.first;
            int idx=it.second;
            
            while(!pq.empty())
            {
                auto [v,i,j]=pq.top();
                
                if(v>=qr)break;
                else
                {
                    pq.pop();
                    cnt++;
                }
                
                if(i>0 && !vis[i-1][j])pq.push({grid[i-1][j],i-1,j}),vis[i-1][j]=1;
                if(i<n-1 && !vis[i+1][j])pq.push({grid[i+1][j],i+1,j}),vis[i+1][j]=1;
                if(j>0 && !vis[i][j-1])pq.push({grid[i][j-1],i,j-1}),vis[i][j-1]=1;
                if(j<m-1 && !vis[i][j+1])pq.push({grid[i][j+1],i,j+1}),vis[i][j+1]=1;
                
            }
            
            ans[idx]=cnt;
        }
        return ans;
    }
};