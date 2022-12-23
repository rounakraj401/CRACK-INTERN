class Solution {
public:
//     int solve(vector<int>&prices,int i,int buy,vector<vector<int>>&dp)
//     {
//         if(i>=prices.size())return 0;
//         if(dp[i][buy]!=-1)return dp[i][buy];
        
//         if(buy)
//         {
//             return max(-prices[i]+solve(prices,i+1,0,dp),solve(prices,i+1,1,dp));
//         }
//         else
//         {
//             return max(prices[i]+solve(prices,i+2,1,dp),solve(prices,i+1,0,dp));
//         }
                       
//     }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(prices.size()+2,vector<int>(2,0));
        
        dp[n][0]=dp[n][1]=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<2;j++)
            {
                if(j==1)
                {
                    dp[i][j]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }
                else
                {
                    dp[i][j]=max(prices[i]+dp[i+2][1],dp[i+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};