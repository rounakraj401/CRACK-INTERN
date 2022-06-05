class Solution {
public:
    int fun(vector<int>&a, int tar)
  {
    int n=a.size();
    vector<vector<int>>dp(n,vector<int>(tar+1,0));
    
    if(a[0]==0)dp[0][0]=2;
    else 
        dp[0][0]=1;
    
    if(a[0]!=0 && a[0]<=tar)dp[0][a[0]]=1;
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=tar;j++)
        {
            int nottake=dp[i-1][j];
            int take=0;
            if(a[i]<=j)take=dp[i-1][j-a[i]];
        
           dp[i][j]=(take+nottake);
        }
    }
    return dp[n-1][tar];
  }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n=nums.size();
        int sum=0;
        for(auto &it:nums)sum+=it;
        if((sum-target)%2 || sum<target)return false;
        return fun(nums,(sum-target)/2);
    }
};