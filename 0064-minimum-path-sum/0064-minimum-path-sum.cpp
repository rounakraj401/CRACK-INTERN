class Solution {
public:

    /*int fun(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp)
    {
        if(i==0 && j==0)return grid[i][j];
        if(i<0 || j<0)return 1000;
        if(dp[i][j]!=-1)return dp[i][j];
        int temp=min(grid[i][j]+fun(i-1,j,grid,dp), grid[i][j]+fun(i,j-1,grid,dp));
        return dp[i][j]=temp;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));

        return fun(m-1,n-1,grid,dp);
    }
};
*/
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int dp[n+1][m+1];
        
//        vector<int>prev(m+1,0);
//        vector<int>curr(m+1,0);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 && j==0)dp[i][j]=grid[i][j];
                else
                {
                    int right=1000;
                    int down=1000;
                    if(i>0)down=grid[i][j]+dp[i-1][j];
                    if(j>0)right=grid[i][j]+dp[i][j-1];
                    
                    dp[i][j]=min(down,right);
                }
            }
        }
        return dp[n-1][m-1];
    }
};
    