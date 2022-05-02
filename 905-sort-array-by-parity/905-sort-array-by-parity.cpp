class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int>ans(nums.size());
        int l=0;
        int r=nums.size()-1;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0)
            {
                ans[l]=nums[i];
                l++;
            }
            else
            {
                ans[r]=nums[i];
                r--;
            }
        }
        return ans;
    }
};