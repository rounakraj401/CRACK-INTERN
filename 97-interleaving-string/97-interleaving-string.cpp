class Solution {
public:
    
//     RECURSIVE + MEMOIZATION
    
//     bool fun(string &s1,string &s2,string &s3,int i,int j,int k,vector<vector<int>>&dp)
//     {
//         if(i==s1.size() && j==s2.size() && k==s3.size())return true;
        
//         if(i>s1.size() || j>s2.size())return false;
        
//         if(dp[i][j]!=-1)return dp[i][j];
        
//         if(s1[i]==s3[k] && s2[j]==s3[k])
//         {
//             return dp[i][j]=fun(s1,s2,s3,i+1,j,k+1,dp) || fun(s1,s2,s3,i,j+1,k+1,dp);
//         }
//         else if(s1[i]==s3[k])
//         {
//             return dp[i][j]=fun(s1,s2,s3,i+1,j,k+1,dp);
//         }
//         else if(s2[j]==s3[k])
//         {
//             return dp[i][j]=fun(s1,s2,s3,i,j+1,k+1,dp);
//         }
//         else
//             return dp[i][j]=false;
//     }
    
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.length();
        int n2=s2.length();
        
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
//        return fun(s1,s2,s3,0,0,0,dp);
        
        if(n1+n2!=s3.size())return false;
        
        for(int i=n1;i>=0;i--)
        {
            for(int j=n2;j>=0;j--)
            {
                int k=i+j;
                if(i==n1 && j==n2)dp[i][j]=1;
                
                else if(s1[i]==s3[k] && s2[j]==s3[k]) dp[i][j]=dp[i+1][j] || dp[i][j+1];
                else if(s1[i]==s3[k]) dp[i][j]=dp[i+1][j];
                else if(s2[j]==s3[k]) dp[i][j]=dp[i][j+1];
                else
                    dp[i][j]=0;
            }
        }
        return dp[0][0];
        
    }
};