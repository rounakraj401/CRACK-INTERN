class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxm=*max_element(nums.begin(),nums.end());

        int ans=0;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==maxm)
            {
                cnt++;
                ans=max(ans,cnt);
            }
            else
                cnt=0;
        }
        return ans;
    }
};