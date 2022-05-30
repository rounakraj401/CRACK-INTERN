class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>>dp(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
        
        for(int i=1;i<=strs.size();i++)
        {
            int cntz=count(strs[i-1].begin(),strs[i-1].end(),'0');
            int cnto=strs[i-1].size()-cntz;
            
            for(int j=0;j<=m;j++)
            {
             for(int k=0;k<=n;k++)
              {
                 if(j-cntz>=0 && k-cnto>=0)
                     dp[i][j][k]=max(dp[i-1][j][k],1+dp[i-1][j-cntz][k-cnto]);
                 else
                     dp[i][j][k]=dp[i-1][j][k];
              }
            }
        }
        return dp[strs.size()][m][n];
    }
//     }
//     int fun(vector<string>&strs ,int m,int n,int idx,vector<vector<vector<int>>>&dp)
//     {
//         if(idx==strs.size())return 0;
        
//         if(dp[m][n][idx]!=-1)return dp[m][n][idx];
        
//         int cntz=count(strs[idx].begin(),strs[idx].end(),'0');
//         int cnto=strs[idx].size()-cntz;
        
//         if(m-cntz>=0 && n-cnto>=0)      
//           return dp[m][n][idx]=max(1+fun(strs,m-cntz,n-cnto,idx+1,dp),fun(strs,m,n,idx+1,dp));
        
//         return dp[m][n][idx]=fun(strs,m,n,idx+1,dp);
//     }
    
};