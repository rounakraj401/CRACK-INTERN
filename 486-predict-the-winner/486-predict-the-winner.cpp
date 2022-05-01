class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        
        int score=fun(nums,0,nums.size()-1);
        
        int total=0;
        for(auto it:nums)total+=it;
        
        return score>=total-score;
    }
    
    int fun(vector<int>&nums,int i,int j)
    {
        if(i>j)return 0;
        if(i==j)return nums[i];
        
        int curr=max(nums[i]+min(fun(nums,i+2,j) , fun(nums,i+1,j-1)) , nums[j]+min(fun(nums,i,j-2) ,fun(nums,i+1,j-1) ));
        
        return curr;
    }
};