class Solution {
public:
    // GENERALISED SOLUTION FOR N FLOORS AND K EGGS
    
    int fun(int n,int e,vector<vector<int>>&dp)
    {
        if(e==1 || n<2)return n;
        
        if(dp[n][e]!=-1)return dp[n][e];
        
        int l=1;
        int h=n;
        int minm=INT_MAX;
        
        while(l<=h)
        {
            int mid=(l+h)/2;
            int egg_break=fun(mid-1,e-1,dp);
            int egg_not_break=fun(n-mid,e,dp);
            
            if(egg_break<egg_not_break)l=mid+1;
            else
                h=mid-1;
            
            int temp=1+max(egg_break,egg_not_break);
            minm=min(minm,temp);
        }
        
        return dp[n][e]=minm;
    }
    int twoEggDrop(int n) {
        int k=2;
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return fun(n,2,dp);
    }
};