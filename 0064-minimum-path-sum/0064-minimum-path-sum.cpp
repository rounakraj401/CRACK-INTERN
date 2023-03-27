class Solution {
public:

    int fun(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp)
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

//     int minPathSum(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//   //       int dp[m+1][n+1];
        
//         vector<int>prev(m+1,0);
//         vector<int>curr(m+1,0);
        
//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(i==0 && j==0)curr[j]=grid[i][j];
//                 else
//                 {
//                     int right=1000;
//                     int down=1000;
//                     if(i>0)down=grid[i][j]+prev[j];
//                     if(j>0)right=grid[i][j]+curr[j-1];
                    
//                     curr[j]=min(down,right);
//                 }
//             }
//             prev=curr;
//         }
//         return prev[n-1];
//     }
};
    