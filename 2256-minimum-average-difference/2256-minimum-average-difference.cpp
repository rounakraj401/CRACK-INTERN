class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        vector<long long int>nums1(n);
        nums1[0]=nums[0];
        
        for(int i=1;i<n;i++)
        {
            nums1[i]=nums[i]+nums1[i-1];
        }
        long long int sum=nums1[n-1];
        
        if(n==1)
            return 0;
        
        long long int minm=INT_MAX;
        long long int ans;
        
        for(int i=0;i<n;i++)
        {
            int a=(floor)(nums1[i]/(double)(i+1));
            
            int b=0;
            if(i!=n-1)
                b=(floor)((sum-nums1[i])/(double)(n-i-1));
            
            if(abs(a-b)<minm)
            {
                minm=abs(a-b);
                ans=i;
            }
        }
        return ans;
    }
};