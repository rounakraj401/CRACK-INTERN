class Solution {
public:
    bool search(vector<int>& nums, int x) {
        int n=nums.size();
        int l=0;
        int h=n-1;
        int ans=-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(nums[mid]==x)
            {
                return true;
            }
            
            // due to duplicates we can not decide which part to go if below condition holds.
            if(nums[l]==nums[mid] && nums[mid]==nums[h])
            {
                l++;
                h--;
            }
            
            else if(nums[mid]>=nums[l])
            {
                if(x>=nums[l] && x<=nums[mid])
                {
                    h=mid;
                }
                else
                    l=mid+1;
            }
            else
            {
                if(x>=nums[mid] &&  x<=nums[h])
                {
                    l=mid;
                }
                else
                    h=mid-1;
            }
        }
        return false;
    }
};