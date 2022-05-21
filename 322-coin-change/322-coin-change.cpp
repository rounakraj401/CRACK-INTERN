class Solution {
public:
/*    int fun(vector<int>&coins, int n, int sum,vector<vector<int>>&dp)
    {
        if(n==0){
          if(sum%coins[0]==0)
            return sum/coins[0];
          else
            return 1e9;
        }
        if(dp[n][sum]!=-1)return dp[n][sum];
        
        int take=INT_MAX;
        if(coins[n]<=sum)take=1+fun(coins,n,sum-coins[n],dp);
        int nottake=fun(coins,n-1,sum,dp);
        
        return dp[n][sum]=min(take,nottake);
        
    }
*/
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        for(int i=0;i<=amount;i++)
        {
            if(i%coins[0]==0)dp[0][i]=i/coins[0];
            else
                dp[0][i]=1e9;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=amount;j++)
            {
                int nottake=dp[i-1][j];
                int take=INT_MAX;
                if(coins[i]<=j)take=1+dp[i][j-coins[i]];
                
                dp[i][j]=min(take,nottake);
            }
        }
        int ans=dp[n-1][amount];
        if(ans>=1e9)return -1;
        else
            return ans;
    }
};