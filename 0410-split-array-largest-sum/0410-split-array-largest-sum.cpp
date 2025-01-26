class Solution {
public:
    bool check(vector<int>&nums , int k , int tot)
    {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum>tot)
            {
                sum=nums[i];
                k--;
            }
        }
        return k>=1;
    }

    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);

        int l=0;
        int h=sum;
        int ans=sum;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(check(nums, k, mid))
            {
                ans=mid;
                h=mid-1;
            }
            else
             l=mid+1;
        }
        return ans;
    }
};