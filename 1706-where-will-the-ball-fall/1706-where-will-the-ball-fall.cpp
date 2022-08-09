class Solution {
public:
    int fun(int r,int c,int n,int m,vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
        if(r==n)return c;
        if(c==0 && grid[r][c]==-1)return -1;
        if(c==m-1 && grid[r][c]==1)return -1;
        
        if(dp[r][c]!=-1)return dp[r][c];
        
        if(grid[r][c]==1 && grid[r][c+1]==1)
        {
           return dp[r][c]=fun(r+1,c+1,n,m,grid,dp);
        }
        if(grid[r][c]==-1 && grid[r][c-1]==-1)
        {
           return dp[r][c]=fun(r+1,c-1,n,m,grid,dp);
        }
        return dp[r][c]=-1;
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int>ans;
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<m;i++)
        {
            ans.push_back(fun(0,i,n,m,grid,dp));
        }
        return ans;
    }
};