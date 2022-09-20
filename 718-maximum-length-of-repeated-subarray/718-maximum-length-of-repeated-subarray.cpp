class Solution {
public:
    int ans=0;
    int fun(int i,int j,vector<int>&nums1,vector<int>&nums2,vector<vector<int>>&dp)
    {
        if(i<0 || j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int cur=0;
        if(nums1[i]==nums2[j])
        {
            cur=1+fun(i-1,j-1,nums1,nums2,dp);
        }
        ans=max(ans,cur);
        
        fun(i-1,j,nums1,nums2,dp);
        fun(i,j-1,nums1,nums2,dp);
        
        return dp[i][j]=cur;
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        fun(n-1,m-1,nums1,nums2,dp);
        return ans;
    }
};