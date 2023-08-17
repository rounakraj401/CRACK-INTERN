class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                   q.push({i,j});
                    vis[i][j]=1;
                    dis[i][j]=0;
                }
            }
        }
        
        int arrx[]={0,1,0,-1};
        int arry[]={1,0,-1,0};
        
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int dx=x+arrx[i];
                int dy=y+arry[i];
                
                
                if(dx<n && dy<m && dx>=0 && dy>=0)
                {
                    if(dis[dx][dy]>dis[x][y]+1)
                        dis[dx][dy]=dis[x][y]+1;
                    
                    if(!vis[dx][dy])
                    {
                        q.push({dx,dy});
                        vis[dx][dy]=1;
                    }
                }
            }
            
        }
        return dis;
    }
};