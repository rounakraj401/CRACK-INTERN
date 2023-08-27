class Solution {
public:
    bool fun(int idx,int k,int n,vector<int>&stones,vector<vector<int>>&dp)
    {
        if(idx==n-1)return true;
        if(idx>=n)return false;
        
        if(dp[idx][k]!=-1)return dp[idx][k];
        
        bool ans=false;
        
        for(int j=-1;j<=1;j++)
        {
            int ns=k+j;
            if(ns>0)
            {
                int in=lower_bound(stones.begin(),stones.end(),stones[idx]+ns)-stones.begin();
                if(in==n || stones[in]!=stones[idx]+ns)
                    continue;
                
                ans=ans || fun(in,ns,n,stones,dp);
            }
        }
        return dp[idx][k]=ans;
    }
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        vector<vector<int>>dp(2001,vector<int>(2001,-1));
        return fun(0,0,n,stones,dp);
    }
};