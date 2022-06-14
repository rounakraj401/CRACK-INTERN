class Solution {
public:
    int solve(vector<int>&prices,int idx,int buy,vector<vector<int>>&dp)
    {
        if(idx==prices.size())return 0;
        
        if(dp[idx][buy]!=-1)return dp[idx][buy];
        
        int profit=0;
        if(buy)
        {
            int profit1=-prices[idx]+solve(prices,idx+1,0,dp);
            int profit2=solve(prices,idx+1,1,dp);
            
            profit=max(profit1,profit2);
        }
        else
        {
            int profit3=prices[idx]+solve(prices,idx+1,1,dp);
            int profit4=solve(prices,idx+1,0,dp);
            
            profit=max(profit3,profit4);
        }
        return dp[idx][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
         vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solve(prices,0,1,dp);
    }
};