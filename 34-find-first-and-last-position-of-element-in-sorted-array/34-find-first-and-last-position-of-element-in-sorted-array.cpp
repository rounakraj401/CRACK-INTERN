class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int temp1=-1;
        int temp2=-1;
        vector<int>ans;
        int n=nums.size();
        int l=0;
        int h=n-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(nums[mid]<target)
                l=mid+1;
            else if(nums[mid]>target)
                h=mid-1;
            else
            {
                temp1=mid;
                h=mid-1;
            }
        }
         l=0;
         h=n-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(nums[mid]>target)
                h=mid-1;
            else if(nums[mid]<target)
                l=mid+1;
            else
            {
                temp2=mid;
                l=mid+1;
            }
        }
        ans.push_back(temp1);
        ans.push_back(temp2);
        return ans;
    }
};