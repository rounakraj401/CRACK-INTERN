class Solution {
public:
    int maxProfit(int z, vector<int>& prices) {
         int n=prices.size();
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(z+1,0)));
        
        if(n==1)return 0;
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<2;j++)
            {
                for(int k=1;k<z+1;k++)
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
        return dp[0][1][z];
    }
};