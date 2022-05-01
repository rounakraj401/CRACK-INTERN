class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        
        int n=nums.size()-1;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int score=fun(nums,0,n,dp);
        
        int total=0;
        for(auto it:nums)total+=it;
        
        return score>=total-score;
    }
    
    int fun(vector<int>&nums,int i,int j,vector<vector<int>>&dp)
    {
        if(i>j)return 0;
        if(i==j)return nums[i];
        
        if(dp[i][j]!=-1)return dp[i][j];
        
int curr=max(nums[i]+min(fun(nums,i+2,j,dp),fun(nums,i+1,j-1,dp)),nums[j]+min(fun(nums,i,j-2,dp),fun(nums,i+1,j-1,dp)));
        
        return dp[i][j]=curr;
    }
};