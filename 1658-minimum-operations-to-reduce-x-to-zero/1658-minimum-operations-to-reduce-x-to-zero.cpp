class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
         int n=nums.size();
         
         int j=0;
         int tar=-x;
        
         for(int i:nums)
             tar+=i;
        
        if(tar<0)return -1;
        
        if(tar==0)return n;
        
        int sum=0;
        int ans=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            while(sum>tar)
            {
                sum-=nums[j];
                j++;
            }
            if(sum==tar)
            {
                ans=max(ans,i-j+1);
            }
        }
        return ans==INT_MIN?-1:n-ans;
    }
};