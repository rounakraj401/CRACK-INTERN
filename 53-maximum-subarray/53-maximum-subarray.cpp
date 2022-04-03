class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            ans=max(ans,sum);
            if(sum<=0)
            {
                sum=0;
            }
        }
        if(ans==0)
        {
            ans=-10000;
            for(int i=0;i<n;i++)
            {
                if(nums[i]<=0)
                ans=max(ans,nums[i]);
            }
        }
        return ans;
    }
};