class Solution {
public:
    bool check(int mid,vector<int>&nums,int p)
    {
        int cnt=0;
        int i=0;
        while(i<nums.size()-1)
        {
            if(abs(nums[i]-nums[i+1])<=mid)
            {
                i+=2;
                cnt++;
            }
            else
                i++;
        }
        return cnt>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int maxm=*max_element(nums.begin(),nums.end());
        int ans;
        
        sort(nums.begin(),nums.end());
        
        int l=0;
        int h=1e9;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(check(mid,nums,p))
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