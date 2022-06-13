class Solution {
public:
//     int solve(string &p,string &s,int i,int j,vector<vector<int>>&dp)
//     {
//         if(i<0 && j<0)return true;
         
//         if(i<0 && j>=0)return false;
//         if(i>=0 && j<0)
//         {
//             for(int k=0;k<=i;k++)
//                 if(p[k]!='*')return false;
            
//             return true;
//         }
        
//         if(dp[i][j]!=-1)return dp[i][j];
        
//         if(p[i]==s[j] || p[i]=='?')
//         {
//             return solve(p,s,i-1,j-1,dp);
//         }
//         else if(p[i]=='*')
//         {
//             return solve(p,s,i-1,j,dp) || solve(p,s,i,j-1,dp);
//         }
//         return false;
//     }
    bool isMatch(string s, string p) {
        int n=p.length();
        int m=s.length();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,0));
        
        dp[0][0]=1;
        
        for(int j=1;j<=m;j++)
            dp[0][j]=0;
        
        for(int i=1;i<=n;i++)
        {
            dp[i][0]=1;
            
            for(int k=1;k<=i;k++)
                 if(p[k-1]!='*')dp[i][0]=0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(p[i-1]==s[j-1] || p[i-1]=='?')
                    dp[i][j]=dp[i-1][j-1];
                else if(p[i-1]=='*')
                    dp[i][j]=dp[i-1][j] | dp[i][j-1];
                else
                    dp[i][j]=0;
            }
            
        }
        return dp[n][m];
    }
};