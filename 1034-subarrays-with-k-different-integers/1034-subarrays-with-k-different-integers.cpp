class Solution {
public:
    int fun(vector<int>&nums , int k)
    {
        unordered_map<int,int>mp;
        int n=nums.size();

        int i=0,j=0,cnt=0;
        while(i<n)
        {
            mp[nums[i]]++;

            while(mp.size()>k)
            {
                mp[nums[j]]--;
                if(mp[nums[j]]==0)mp.erase(nums[j]);
                j++;
            }

            cnt+=i-j+1;
            i++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return fun(nums , k)-fun(nums , k-1);
    }
};