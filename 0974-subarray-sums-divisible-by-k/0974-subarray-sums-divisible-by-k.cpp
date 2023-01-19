class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int>pref(k,0);
        pref[0]++;
        int ans=0;
        int cursum=0;
        
        for(int i=0;i<nums.size();i++)
        {
            cursum=(cursum+nums[i]%k+k)%k;
            ans+=pref[cursum];
            
            pref[cursum]++;
        }
        return ans;
    }
};