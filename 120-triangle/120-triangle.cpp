class Solution {
public:
/*    int fun(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& triangle,int n)
    {
        if(i==n-1)return triangle[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        
        int d1=triangle[i][j]+fun(i+1,j,dp,triangle,n);
        int d2=triangle[i][j]+fun(i+1,j+1,dp,triangle,n);
        
        return dp[i][j]=min(d1,d2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return fun(0,0,dp,triangle,n);
    }
};
*/
int minimumTotal(vector<vector<int>>& triangle) {
      int n=triangle.size();
      int dp[n+1][n+1];
      
    for(int j=0;j<n;j++)
    {
        dp[n-1][j]=triangle[n-1][j];
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=i;j>=0;j--)
        {
            int d1=triangle[i][j]+dp[i+1][j];
            int d2=triangle[i][j]+dp[i+1][j+1];
            
            dp[i][j]=min(d1,d2);
        }
    }
    return dp[0][0];
}
};

    