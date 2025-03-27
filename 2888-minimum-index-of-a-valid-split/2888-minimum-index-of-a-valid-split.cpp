class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it:nums)mp[it]++;
        
        int maxm=-1;
        int maxf=0;
        for(auto it:mp)
        {
            if(maxf<it.second)
            {
                maxf=it.second;
                maxm=it.first;
            }
        }
        
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==maxm)cnt++;
            
            if(cnt*2>i+1)
            {
                if((maxf-cnt)*2>n-i-1)
                    return i;
                return -1;
            }
        }
        return -1;
    }
};