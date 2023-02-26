class Solution {
public:
//     int solve(string w1,string w2,int i,int j,vector<vector<int>>&dp)
//     {
//         if(i<0)return j+1;
//         if(j<0)return i+1;
        
//         if(dp[i][j]!=-1)return dp[i][j];
        
//         if(w1[i]==w2[j])
//             return dp[i][j]=solve(w1,w2,i-1,j-1,dp);
//         else{
//         int x=1+solve(w1,w2,i,j-1,dp);  // insert
//         int y=1+solve(w1,w2,i-1,j,dp);  // delete
//         int z=1+solve(w1,w2,i-1,j-1,dp);   // replace
        
//         return dp[i][j]=min(x,min(y,z));
//         }
//     }
    int minDistance(string w1, string w2) {
        int n=w1.size();
        int m=w2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=i;
        }
        for(int j=0;j<=m;j++)
        {
            dp[0][j]=j;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(w1[i-1]==w2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=min(1+dp[i][j-1],min(1+dp[i-1][j-1],1+dp[i-1][j]));
                }
            }
        }
        return dp[n][m];
    }
};