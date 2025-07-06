class Solution {
public:
    // int fun(int idx , int buy , int k , vector<int>&prices , vector<vector<vector<int>>>&dp)
    // {
    //     if(k==0 || idx==prices.size())return 0;
    //     if(dp[idx][buy][k]!=-1)return dp[idx][buy][k];

    //     int profit;
    //     if(buy==0)
    //     {
    //        profit = max( fun(idx+1 , 0 , k , prices , dp) , -prices[idx] +fun(idx+1 , 1 ,k , prices , dp));
    //     } 
    //     if(buy==1)
    //     {
    //         profit = max( fun(idx+1, 1 , k , prices , dp) , prices[idx]+ fun(idx+1 , 0 , k-1 , prices ,dp));
    //     }
    //     return dp[idx][buy][k]=profit;
    // }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2,vector<int>(k+1,0)));

        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<2;j++)
            {
                for(int z=1;z<=k;z++)
                {
                    int profit;
                    if(j==0)
                    {
                        profit = max( dp[i+1][0][z] , -prices[i] + dp[i+1][1][z]);
                    }
                    if(j==1)
                    {
                        profit = max( dp[i+1][1][z] , prices[i] +dp[i+1][0][z-1]);
                    }
                    dp[i][j][z]=profit;
                }
            }
        }
        return dp[0][0][k];
    }
};