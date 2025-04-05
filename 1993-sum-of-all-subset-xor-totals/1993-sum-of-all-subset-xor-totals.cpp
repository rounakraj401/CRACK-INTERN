class Solution {
public:

    int fun(vector<int>&nums , int idx , int currxor)
    {
        if(idx==nums.size()){
         return currxor;
        } 

        int include=fun(nums,idx+1,currxor^nums[idx]);
        int exclude=fun(nums,idx+1,currxor);

        return include+exclude;
    }
    int subsetXORSum(vector<int>& nums){
        return fun(nums,0,0);
    }
};