class Solution {
public:
   
    
    int maxDistance(vector<vector<int>>& grid) {
        
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)q.push({i,j});
            }
        }
        int dist=-1;
        while(!q.empty())
        {
            dist++;
            int x=q.size();
            for(int i=0;i<x;i++){
              auto [r,c]=q.front();
              q.pop();
                
              for(int i=0;i<4;i++)
              {
                  int nx=r+dx[i];
                  int ny=c+dy[i];
                  
                  if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==0)
                  {
                      grid[nx][ny]=1;
                      q.push({nx,ny});
                  }
              }
            }
        }
        return dist==0 ?-1:dist;
    }
};