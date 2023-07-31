class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=int(s1[i-1]) + dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j] , dp[i][j-1]);
            }
        }
        
        int ans=0;
        for(auto it:s1)ans+=int(it);
        for(auto it:s2)ans+=int(it);
        
        return ans-2*dp[n][m];
    }
};