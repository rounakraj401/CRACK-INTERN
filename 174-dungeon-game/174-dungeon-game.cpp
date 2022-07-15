class Solution {
public:
    
    int fun(vector<vector<int>>& dung,int i,int j,int n,int m,vector<vector<int>>& dp)
    {
        if(i==n-1 && j==m-1)return dung[i][j];
        
        if(i>=n || j>=m)return -1e6;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int d=min(dung[i][j],fun(dung,i+1,j,n,m,dp)+dung[i][j]);
        int r=min(dung[i][j],fun(dung,i,j+1,n,m,dp)+dung[i][j]);
        
        return dp[i][j]=max(d,r);
    }
    int calculateMinimumHP(vector<vector<int>>& dung) {
        int n=dung.size();
        int m=dung[0].size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        int ans=fun(dung,0,0,n,m,dp);
        
        if(ans<0)return 1-ans;
        return 1;
    }
};