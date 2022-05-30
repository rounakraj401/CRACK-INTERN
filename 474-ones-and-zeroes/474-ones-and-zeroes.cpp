class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(strs.size(),-1)));
        return fun(strs,m,n,0,dp);
    }
    int fun(vector<string>&strs ,int m,int n,int idx,vector<vector<vector<int>>>&dp)
    {
        if(idx==strs.size())return 0;
        
        if(dp[m][n][idx]!=-1)return dp[m][n][idx];
        
        int cntz=count(strs[idx].begin(),strs[idx].end(),'0');
        int cnto=strs[idx].size()-cntz;
        
        if(m-cntz>=0 && n-cnto>=0)      
          return dp[m][n][idx]=max(1+fun(strs,m-cntz,n-cnto,idx+1,dp),fun(strs,m,n,idx+1,dp));
        
        return dp[m][n][idx]=fun(strs,m,n,idx+1,dp);
    }
    
};