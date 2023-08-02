class Solution {
public:
    // TC-0(N!*N)
    // SC-O(1)
    
    void fun(int idx,vector<int>&nums,vector<vector<int>>&ans)
    {
        if(idx==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++)
        {
            swap(nums[i],nums[idx]);
            fun(idx+1,nums,ans);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>>ans;
//         ans.push_back(nums);
        
//         while(next_permutation(nums.begin(),nums.end()))
//             ans.push_back(next_permutation(nums.begin(),nums.end()));
//         return ans;
//     }
        
        vector<vector<int>>ans;
        fun(0,nums,ans);
        return ans;
    }
};