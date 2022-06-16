class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        int maxm=1;
        int last=0;
        vector<int>dp(n,1);
        vector<int>hash(n);
        
        for(int i=1;i<n;i++)
        {
            hash[i]=i;
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 &&  dp[i]<dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
            if(dp[i]>maxm)
            {
                maxm=dp[i];
                last=i;
            }
        }
        vector<int>ans;
        ans.push_back(nums[last]);
        
        while(hash[last]!=last)
        {
            last=hash[last];
            ans.push_back(nums[last]);
        }
        return ans;
    }
};