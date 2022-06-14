class Solution {
public:
//      int solve(vector<int>&prices,int idx,int buy,vector<vector<vector<int>>>&dp,int cap)
//     {
//          if(cap==0)return 0;
//         if(idx==prices.size())return 0;
        
//         if(dp[idx][buy][cap]!=-1)return dp[idx][buy][cap];
        
//         int profit=0;
//         if(buy)
//         {
//             int profit1=-prices[idx]+solve(prices,idx+1,0,dp,cap);
//             int profit2=solve(prices,idx+1,1,dp,cap);
            
//             profit=max(profit1,profit2);
//         }
//         else
//         {
//             int profit3=prices[idx]+solve(prices,idx+1,1,dp,cap-1);
//             int profit4=solve(prices,idx+1,0,dp,cap);
            
//             profit=max(profit3,profit4);
//         }
//         return dp[idx][buy][cap]=profit;
//     }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,0)));
        
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<2;j++)
//             {
//                 dp[i][j][0]=0;
//             }
//         }
//         for(int j=0;j<2;j++)
//         {
//             for(int k=0;k<3;k++)
//             {
//                 dp[n][j][k]=0;
//             }
//         }
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<2;j++)
            {
                for(int k=1;k<3;k++)
                {
                    if(j==1)
                    {
                        int profit1=-prices[i]+dp[i+1][0][k];
                        int profit2=dp[i+1][1][k];
            
                        dp[i][j][k]=max(profit1,profit2);
                     }
                    else
                    {
                        int profit3=prices[i]+dp[i+1][1][k-1];
                        int profit4=dp[i+1][0][k];
            
                        dp[i][j][k]=max(profit3,profit4);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};