class Solution {
public:
    void fun(int i,vector<vector<int>>&ans,vector<int>&ds,vector<int>&nums)
    {
        ans.push_back(ds);
        for(int j=i;j<nums.size();j++)
        {
            if(j>i && nums[j]==nums[j-1])continue;
            ds.push_back(nums[j]);
            fun(j+1,ans,ds,nums);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>ds;
        fun(0,ans,ds,nums);
        return ans;
    }
};