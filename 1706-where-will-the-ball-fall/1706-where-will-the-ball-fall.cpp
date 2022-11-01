class Solution {
public:
    int fill_ans(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp)
    {
        if(i==grid.size())return j;
        
        if(j==0 && grid[i][j]==-1)
            return -1;
        
        if(j==grid[0].size()-1 && grid[i][j]==1)
            return -1;

        if(dp[i][j]!=-2)return dp[i][j];
        
        if(grid[i][j]==1 && grid[i][j+1]==1)
            return dp[i][j]=fill_ans(i+1,j+1,grid,dp);
        if(grid[i][j]==-1 && grid[i][j-1]==-1)
            return dp[i][j]=fill_ans(i+1,j-1,grid,dp);
        
        return dp[i][j]=-1;
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int>ans(grid[0].size());
        int n=grid[0].size();
        int m=grid.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-2));
        
        for(int i=0;i<n;i++)
        {
            ans[i]=fill_ans(0,i,grid,dp);
        }
        return ans;
    }
};