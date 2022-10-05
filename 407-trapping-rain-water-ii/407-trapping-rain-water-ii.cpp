class Solution {
public:
    vector<int>xx={-1,0,1,0};
    vector<int>yy={0,-1,0,1};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int ans=0;
        
priority_queue< pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> >pq;
        
        int n=heightMap.size();
        int m=heightMap[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0 || i==n-1 || j==m-1)
                {
                    pq.push({heightMap[i][j],{i,j}});
                    vis[i][j]=1;
                }
            }
        }
        int mx=0;
        while(!pq.empty())
        {
            int minm=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            
            
            pq.pop();
            mx=max(mx,minm);
            
          for(int i=0;i<4;i++)
           {
              int nx=x+xx[i];
              int ny=y+yy[i];
              
              if(nx>=0 && nx<n && ny>=0 && ny<m && vis[nx][ny]==0)
              {
                 vis[nx][ny]=1;
                  pq.push({heightMap[nx][ny],{nx,ny}});
                  
                  
                  if(heightMap[nx][ny]<mx)
                      ans+=mx-heightMap[nx][ny];
       //           cout<<ans<<"\n";
              }
           }
        }
        return ans;
    }
};