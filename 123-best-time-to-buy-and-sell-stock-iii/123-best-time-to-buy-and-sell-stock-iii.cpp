class Solution {
public:
     int solve(vector<int>&prices,int idx,int buy,vector<vector<vector<int>>>&dp,int cap)
    {
         if(cap==0)return 0;
        if(idx==prices.size())return 0;
        
        if(dp[idx][buy][cap]!=-1)return dp[idx][buy][cap];
        
        int profit=0;
        if(buy)
        {
            int profit1=-prices[idx]+solve(prices,idx+1,0,dp,cap);
            int profit2=solve(prices,idx+1,1,dp,cap);
            
            profit=max(profit1,profit2);
        }
        else
        {
            int profit3=prices[idx]+solve(prices,idx+1,1,dp,cap-1);
            int profit4=solve(prices,idx+1,0,dp,cap);
            
            profit=max(profit3,profit4);
        }
        return dp[idx][buy][cap]=profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(prices,0,1,dp,2);
    }
};