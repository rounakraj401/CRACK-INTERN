class Solution {
public:
    int fun(int idx,vector<vector<int>>&pairs,int limit,vector<vector<int>>&dp)
    {
        if(idx==pairs.size())return 0;
        
        if(dp[idx][limit+1001]!=-1)
            return dp[idx][limit+1001];
        
        int nottake=fun(idx+1,pairs,limit,dp);
        int take=0;
        if(pairs[idx][0]>limit)
        {
            take=1+fun(idx+1,pairs,pairs[idx][1],dp);
        }
        return dp[idx][limit+1001]=max(take,nottake);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n=pairs.size();
        int limit=-1001;
        
        vector<vector<int>>dp(n+1,vector<int>(2004,-1));
        return fun(0,pairs,limit,dp);
    }
};