class Solution {
public:
    int fun(vector<vector<int>>& grid,int i,int j1,int j2,vector<vector<vector<int>>>&dp)
    {
        int i2=i+j1-j2;
        int n=grid.size();
        if(i>=grid.size() ||i2>=grid.size() ||j1>=grid.size() ||j2>=grid.size() || grid[i][j1]==-1 || grid[i2][j2]==-1)return INT_MIN;
        
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
        
        
        if(i==n-1 && j1==n-1)return grid[i][j1];
        
        int maxi=grid[i][j1];
        if(j1!=j2)maxi+=grid[i2][j2];
        
        int rr=fun(grid,i,j1+1,j2+1,dp);
        int rd=fun(grid,i,j1+1,j2,dp);
        int dr=fun(grid,i+1,j1,j2+1,dp);
        int dd=fun(grid,i+1,j1,j2,dp);
        
        maxi+=max(rr,max(rd,max(dr,dd)));
        
        return dp[i][j1][j2]=maxi;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
        
        return max(0,fun(grid,0,0,0,dp));
    }
};