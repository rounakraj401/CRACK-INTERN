class Solution {
public:
    const int mod=1e9+7;
    long long int dp[1001][1001];
    
    long long fun(int i,int j,int n,int m,vector<vector<int>>&grid)
    {
        if(i<0 || j<0 || i>=n || j>=m)return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        long long int val=1;
        
        if(i+1<n && grid[i+1][j]>grid[i][j])
            val=(val+fun(i+1,j,n,m,grid))%mod;
        
        if(i-1>=0 && grid[i-1][j]>grid[i][j])
            val=(val+fun(i-1,j,n,m,grid))%mod;
        
        if(j+1<m && grid[i][j+1]>grid[i][j])
            val=(val+fun(i,j+1,n,m,grid))%mod;
        
        if(j-1>=0 && grid[i][j-1]>grid[i][j])
            val=(val+fun(i,j-1,n,m,grid))%mod;
        
        return dp[i][j]=val;
        
    }
    
    int countPaths(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof dp );
        
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dp[i][j] == -1)fun(i,j,n,m,grid);
            }
        }
        
        long long int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans=(ans+dp[i][j])%mod;
            }
        }
        return ans;
    }
};