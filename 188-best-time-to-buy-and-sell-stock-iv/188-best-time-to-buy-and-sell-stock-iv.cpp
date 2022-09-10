class Solution {
public:
    int fun(int idx,int n,int k,int canbuy , vector<int>&prices,vector<vector<vector<int>>>&dp)
    {
        if(k==0 || idx==n)
            return 0;
        
        if(dp[idx][k][canbuy]!=-1)return dp[idx][k][canbuy];
        
        int profit=INT_MIN;
        if(canbuy)
        {
             profit=max(profit , -prices[idx]+fun(idx+1,n,k,1-canbuy,prices,dp));
             profit=max(profit , fun(idx+1,n,k,canbuy,prices,dp));
        }
        else
        {
             profit=max(profit , prices[idx]+fun(idx+1,n,k-1,1-canbuy,prices,dp));
             profit=max(profit , fun(idx+1,n,k,canbuy,prices,dp));
        }
        return dp[idx][k][canbuy]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        bool canbuy=1;
        int n=prices.size();
        
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return fun(0,n,k,canbuy,prices,dp);
    }
};