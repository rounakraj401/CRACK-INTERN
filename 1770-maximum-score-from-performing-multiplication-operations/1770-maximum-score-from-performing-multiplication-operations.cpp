class Solution {
public: 
vector<vector<int>>dp;
    
int answer_dp(vector<int> &nums, vector<int> &multi, int i, int l, int r){

	if(i==multi.size())
		return 0;

	if(dp[l][i]!=INT_MIN)
		return dp[l][i];

	int first = multi[i]*nums[l] + answer_dp(nums, multi, i+1, l+1, r);
	int last = multi[i]*nums[r] + answer_dp(nums, multi, i+1, l, r-1);

	dp[l][i] = max(first, last);

	return dp[l][i];
}
int maximumScore(vector<int>& nums, vector<int>& multi) {
    int m=multi.size();
    
 	dp.resize(m+1);
    dp.assign(m+1,vector<int>(m+1,INT_MIN));

	return answer_dp(nums, multi, 0, 0, nums.size()-1);
  }
};