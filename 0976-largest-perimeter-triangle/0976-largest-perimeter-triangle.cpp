class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=INT_MIN;
        bool flag=0;
         while(1)
         {
             int r=n-1;
             int m=r-1;
             int l=r-2;
             
             if(l<0)break;
             
             if(nums[l]+nums[m]<=nums[r] || nums[l]+nums[r]<=nums[m] || nums[r]+nums[m]<=nums[l])
             {
                 n--;
                 continue;
             }
             
             flag=1;
             ans=max(ans,nums[l]+nums[r]+nums[m]);
             n--;
         }
        if(flag==0)return 0;
        return ans;
    }
};