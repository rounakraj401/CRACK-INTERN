class Solution {
public:
//     int fun(vector<int>&nums1,vector<int>&nums2,int idx,bool swapp,vector<vector<int>>&dp)
//     {
//         if(idx==nums1.size())return 0;
        
//         int prev1=nums1[idx-1];
//         int prev2=nums2[idx-1];
//         int ans=INT_MAX;
        
//         if(dp[idx][swapp]!=-1)return dp[idx][swapp];
        
//         if(swapp)
//             swap(prev1,prev2);
        
//         if(nums1[idx]>prev1 && nums2[idx]>prev2)
//             ans=fun(nums1,nums2,idx+1,0,dp);
        
//         if(nums1[idx]>prev2 && nums2[idx]>prev1)
//             ans=min(ans,1+fun(nums1,nums2,idx+1,1,dp));
        
//         return dp[idx][swapp]=ans;
       
//     } 
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        // bool swapp=0;
        // int idx=1;
        
        vector<vector<int>>dp(nums1.size()+1,vector<int>(2,0));
//        return fun(nums1,nums2,idx,0,dp);
        
        for(int idx=nums1.size()-1;idx>=1;idx--)
        {
            for(int j=1;j>=0;j--)
            {
                int prev1=nums1[idx-1];
                int prev2=nums2[idx-1];
                int ans=INT_MAX;
        
                  if(j)
                    swap(prev1,prev2);
        
                   if(nums1[idx]>prev1 && nums2[idx]>prev2)
                     ans=dp[idx+1][0];
        
                   if(nums1[idx]>prev2 && nums2[idx]>prev1)
                     ans=min(ans,1+dp[idx+1][1]);
        
                 dp[idx][j]=ans;
            }
        }
        return dp[1][0];
    }
};