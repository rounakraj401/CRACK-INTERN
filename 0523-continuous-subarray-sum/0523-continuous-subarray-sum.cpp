class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int pref=0;
        
        for(int i=0;i<nums.size();i++)
        {
            pref+=nums[i];
            
            pref%=k;
            
            if(pref==0 && i)return true;
            
            if(mp.find(pref)!=mp.end())
            {
                if(i-mp[pref]>1)return true;
            }
            else
               mp[pref]=i;
        }
        return false;
    }
};