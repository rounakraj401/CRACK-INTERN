class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int idx1=0;
        int idx2=n;
        
        vector<int>vec;
        while(idx1<n)
        {
            vec.push_back(nums[idx1++]);
            vec.push_back(nums[idx2++]);
        }
        
        return vec;
    }
};