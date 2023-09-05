class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum=0;
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            int maxm=INT_MIN;
            int minm=INT_MAX;
            
            for(int j=i;j<n;j++)
            {
                maxm=max(maxm,nums[j]);
                minm=min(minm,nums[j]);
                
                sum+=maxm-minm;
            }
        }
        return sum;
    }
};