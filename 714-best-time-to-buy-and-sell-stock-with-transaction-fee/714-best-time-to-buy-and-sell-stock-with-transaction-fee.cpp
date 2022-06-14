class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        
        dp[n][0]=dp[n][1]=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<2;j++)
            {
                if(j==0)
                {
                int profit3=prices[i]+dp[i+1][1]-fee;
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