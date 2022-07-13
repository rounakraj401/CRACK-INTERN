class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        int tot=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!=0)tot++;
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        int cnt=0;
        int dx[4]={0,0,+1,-1};
        int dy[4]={+1,-1,0,0};
        int ans=0;
        while(!q.empty())
        {
            int k=q.size();
            cnt+=k;
            while(k--)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    
                    if(nx<0 || nx>=n || ny<0 || ny>=m || grid[nx][ny]!=1)continue;
                    
                    grid[nx][ny]=2;
                    q.push({nx,ny});
                    
                }
            }
            if(!q.empty())ans++;
        }
        return tot==cnt?ans:-1;
    }
};