class Solution {
public:
//     int solve(int i,int prev,vector<int>&nums,int n,vector<vector<int>>&dp)
//     {
//         if(i==n)return 0;
//         if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        
//         int len=solve(i+1,prev,nums,n,dp);
//         if(prev==-1 || nums[i]>nums[prev])
//         {
//             len=max(len,1+solve(i+1,i,nums,n,dp));
//         }
//         return dp[i][prev+1]=len;
//     }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>next(n+1,0),cur(n+1,0);
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i-1;j>=-1;j--)
            {
                cur[j+1]=next[j+1];
                if(j==-1 || nums[i]>nums[j])
                    cur[j+1]=max(cur[j+1],1+next[i+1]);
            }
            next=cur;
        }
        return next[0];
    }
};

