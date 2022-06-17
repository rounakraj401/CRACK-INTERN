class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        
        int sum=0;
        int ans=0;
        mp[sum]++;
        
        for(auto it:nums)
        {
            sum+=it;
            
            int x=sum-k;
            if(mp.count(x)>0)
                ans+=mp[x];
            
            mp[sum]++;
        }
        return ans;
    }
};