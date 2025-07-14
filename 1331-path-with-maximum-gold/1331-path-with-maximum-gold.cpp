class Solution {
public:
    int ans=0;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,-1,0,1};

    int fun(int row,int col, vector<vector<int>>&grid)
    {
        int n=grid.size();
        int m=grid[0].size();

        if(row<0 || row>=n ||col<0 ||col>=m || grid[row][col]==0)return 0;

        int curr=grid[row][col];
        int localMaxm=curr;

        grid[row][col]=0;

        for(int i=0;i<4;i++)
        {
            int newx=row+dx[i];
            int newy=col+dy[i];

           localMaxm=max(localMaxm, curr + fun(newx,newy,grid));
        }
        grid[row][col]=curr;
        return localMaxm;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!=0)
                {
                    ans=max(ans, fun(i,j,grid));
                }
            }
        }
        return ans;
    }
};