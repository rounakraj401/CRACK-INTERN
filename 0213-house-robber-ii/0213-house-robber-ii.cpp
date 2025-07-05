class Solution {
public:
    int fun(int idx , vector<int>&nums , vector<int>&dp)
    {
         if(idx==0)return nums[0];
         if(dp[idx]!=-1)return dp[idx];

         int take=nums[idx];
          if(idx>1)take+= fun(idx-2,nums,dp);
         int nottake = fun(idx-1,nums,dp);

         return dp[idx]=max(take , nottake);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        
        vector<int>dp1(n+1,-1);
        vector<int>dp2(n+1,-1);
        vector<int>nums1,nums2;
        for(int i=0;i<n;i++)
        {
            if(i!=0)nums1.push_back(nums[i]);
            if(i!=n-1)nums2.push_back(nums[i]);
        }
        int n1=nums1.size();
        int n2=nums2.size();

        int way1=fun(n1-1 , nums1 , dp1);
        int way2=fun(n2-1 , nums2 , dp2);

        return max(way1,way2);
    }
};