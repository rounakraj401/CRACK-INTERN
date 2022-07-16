class Solution {
public:
    long long mod=1e9+7;
    
    int fun(int i,int j,int move,int n,int m,vector<vector<vector<long long>>>&dp)
    {
        if(i<0 || i>=n || j<0 || j>=m)return 1;
        if(move<=0)return 0;
        
        if(dp[i][j][move]!=-1)return dp[i][j][move];
        
        int up=fun(i-1,j,move-1,n,m,dp);
        int down=fun(i+1,j,move-1,n,m,dp);
        int right=fun(i,j+1,move-1,n,m,dp);
        int left=fun(i,j-1,move-1,n,m,dp);
        
        return dp[i][j][move]=(up%mod+down%mod+left%mod+right%mod)%mod;
    }
    int findPaths(int n, int m, int move, int startRow, int startColumn) {
        vector<vector<vector<long long>>>dp(n+1,vector<vector<long long>>(m+1,vector<long long>(move+1,-1)));
        
        return fun(startRow,startColumn,move,n,m,dp);
    }
};