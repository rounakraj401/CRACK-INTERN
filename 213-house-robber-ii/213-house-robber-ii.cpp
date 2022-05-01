class Solution {
public:
    int fun(vector<int>&vec)
    {
        int n1=vec.size();
        vector<int>dp(n1+1,-1);
       
        dp[0]=vec[0];
        for(int i=1;i<n1;i++)
        {
            int pick=vec[i];
            if(i>1)pick+=dp[i-2];
            
            int notpick=0+dp[i-1];
            
            dp[i]=max(pick,notpick);
        }
        return dp[n1-1];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int>temp1;
        vector<int>temp2;
        for(int i=0;i<n;i++)
        {
            if(i!=0)temp1.push_back(nums[i]);
            if(i!=n-1)temp2.push_back(nums[i]);
        }
        return max(fun(temp1),fun(temp2));
    }
};