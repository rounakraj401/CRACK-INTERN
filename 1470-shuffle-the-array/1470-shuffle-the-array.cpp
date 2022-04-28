class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        
        for(int x=0; x < n; x++){
            ans.push_back(nums[x]);
            ans.push_back(nums[n+x]);
        }
        
        
        return ans;
    }
};