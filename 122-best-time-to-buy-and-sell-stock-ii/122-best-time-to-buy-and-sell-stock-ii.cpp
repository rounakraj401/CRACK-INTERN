class Solution {
public:
//     int solve(vector<int>&prices,int idx,int buy,vector<vector<int>>&dp)
//     {
//         if(idx==prices.size())return 0;
        
//         if(dp[idx][buy]!=-1)return dp[idx][buy];
        
//         int profit=0;
//         if(buy)
//         {
//             int profit1=-prices[idx]+solve(prices,idx+1,0,dp);
//             int profit2=solve(prices,idx+1,1,dp);
            
//             profit=max(profit1,profit2);
//         }
//         else
//         {
//             int profit3=prices[idx]+solve(prices,idx+1,1,dp);
//             int profit4=solve(prices,idx+1,0,dp);
            
//             profit=max(profit3,profit4);
//         }
//         return dp[idx][buy]=profit;
//     }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        
        dp[n][0]=dp[n][1]=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<2;j++)
            {
                if(j==0)
                {
                int profit3=prices[i]+dp[i+1][1];
                int profit4=dp[i+1][0];
                    
                dp[i][j]=max(profit3,profit4);
                }
                else
                {
                    int profit1=-prices[i]+dp[i+1][0];
                    int profit2=dp[i+1][1];
                    
                dp[i][j]=max(profit1,profit2);
                }
            }
        }
        return dp[0][1];
    }
};