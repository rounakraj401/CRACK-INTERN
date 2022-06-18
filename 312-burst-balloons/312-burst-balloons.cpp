class Solution {
public:
//     int solve(vector<int>&cuts,int i,int j,vector<vector<int>>&dp)
//     {
//         if(i>j)return 0;
//         if(dp[i][j]!=-1)return dp[i][j];
        
//         int maxm=INT_MIN;
//         for(int k=i;k<=j;k++)
//         {
//             maxm=max(maxm,cuts[i-1]*cuts[j+1]*cuts[k]+solve(cuts,i,k-1,dp)+solve(cuts,k+1,j,dp));
//         }
//         return dp[i][j]=maxm;
//     }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
//        return solve(nums,1,n,dp);
        
        for(int i=n;i>=1;i--)
        {
            for(int j=1;j<=n;j++)
            {
                if(i>j)continue;
                int maxm=INT_MIN;
                for(int k=i;k<=j;k++)
                {
                    maxm=max(maxm,nums[i-1]*nums[k]*nums[j+1]+dp[i][k-1]+dp[k+1][j]);
                }
                dp[i][j]=maxm;
            }
        }
        return dp[1][n];
    }
};