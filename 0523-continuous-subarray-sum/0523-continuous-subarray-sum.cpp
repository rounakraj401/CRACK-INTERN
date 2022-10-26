class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int>st;
        
        int sum=0;
        int pre=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];            
            int mod=(k==0)?sum:sum%k;
            if(st.count(mod))
                return true;
            st.insert(pre);
            
            pre=mod;
        }
        return false;
    }
};