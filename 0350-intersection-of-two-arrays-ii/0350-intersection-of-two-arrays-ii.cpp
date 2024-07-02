class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp1,mp2;
        for(auto it:nums1)
        {
            mp1[it]++;
        }
        for(auto it:nums2)
        {
            mp2[it]++;
        }
        vector<int>ans;
        for(auto it:mp2)
        {
            if(mp1.find(it.first)!=mp1.end())
            {
                int x=min(mp1[it.first],it.second);
                while(x--)ans.push_back(it.first);
            }
        }
        return ans;
    }
};