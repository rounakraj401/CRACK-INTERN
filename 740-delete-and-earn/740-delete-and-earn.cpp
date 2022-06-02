class Solution {
public:
    int solve(vector<int>&arr,int i,vector<int>&dp)
    {
        int n=arr.size();
        if(i>=arr.size())return 0;
        
        if(dp[i]!=-1)return dp[i];
        
        int currv=arr[i];
        int currs=arr[i];
        int idx=i+1;
        
        while(idx<n  && arr[idx]==currv)
        {
            currs+=arr[idx];
            idx++;
        }
        while(idx<n && arr[idx]==currv+1)
        {
            idx++;
        }
        return dp[i]=max(currs+solve(arr,idx,dp),solve(arr,i+1,dp));
    }
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(20001,-1);
        return solve(nums,0,dp);
        
    }
};