class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(1001,0));
        
        int ans=1;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int d=nums[i]-nums[j]+500;
                dp[i][d]=1+dp[j][d];
                
                ans=max(ans,dp[i][d]);
            }
        }
        return ans+1;
    }
};