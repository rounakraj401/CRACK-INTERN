class Solution {
public:
    int fun(vector<int>&nums,int goal)
    {
        if(goal<0)
            return 0;
        int n=nums.size();
        int sum=0;
        int i=0,j=0;
        int ans=0;
        
        while(i<n)
        {
            sum+=nums[i];
            
            while(sum>goal)
            {
                sum-=nums[j++];
            }
            ans+=(i-j+1);
            i++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return fun(nums,goal)-fun(nums,goal-1);
    }
};