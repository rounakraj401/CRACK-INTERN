class Solution {
public:
/*  int fun(int n,vector<int>& cost,vector<int>& dp)
    {
       if(n<2)return 0;
        if(dp[n]!=-1)return dp[n];
        
        int left=fun(n-1,cost,dp)+cost[n-1];
        int right=INT_MAX;
        if(n>1)
            right=fun(n-2,cost,dp)+cost[n-2];
        
        return dp[n]=min(left,right);
    }*/
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
         int prev2=0;
         int prev=0;
        int cur;
        for(int i=2;i<=n;i++)
        {
            int left=prev+cost[i-1];
        
            int right=prev2+cost[i-2];
            cur=min(left,right);
            prev2=prev;
            prev=cur;
        }
        return prev;
        
    }
};