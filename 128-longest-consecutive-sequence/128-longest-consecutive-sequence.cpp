class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(st.find(nums[i]-1)!=st.end())continue;
            else
            {
                int cur=nums[i];
                int cnt=0;
                while(st.find(cur)!=st.end())
                {
                    cnt++;
                    cur++;
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};