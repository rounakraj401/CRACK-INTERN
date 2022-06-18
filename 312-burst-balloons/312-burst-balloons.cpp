class Solution {
public:
    int solve(vector<int>&cuts,int i,int j,vector<vector<int>>&dp)
    {
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        
        int maxm=INT_MIN;
        for(int k=i;k<=j;k++)
        {
            maxm=max(maxm,cuts[i-1]*cuts[j+1]*cuts[k]+solve(cuts,i,k-1,dp)+solve(cuts,k+1,j,dp));
        }
        return dp[i][j]=maxm;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp;
        temp.push_back(1);
        for(int i=0;i<n;i++)temp.push_back(nums[i]);
        temp.push_back(1);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(temp,1,n,dp);
    }
};