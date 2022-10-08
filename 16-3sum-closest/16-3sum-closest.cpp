class Solution {
public:
    int threeSumClosest(vector<int>& nums, int tar) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        int diff=INT_MAX;
        int sum=0;
        for(int i=0;i<n-2;i++)
        {
            int idx1=i;            
            int idx2=i+1;
            int idx3=n-1;
            
            while(idx2<idx3)
            {
                if(nums[idx1]+nums[idx2]+nums[idx3]==tar)
                    return tar;
                else
                {
                   if(abs(nums[idx1]+nums[idx2]+nums[idx3]-tar)<diff)
                   {
                       diff=abs(nums[idx1]+nums[idx2]+nums[idx3]-tar);
                       sum=nums[idx1]+nums[idx2]+nums[idx3];
                   }
               }
                
                if(nums[idx1]+nums[idx2]+nums[idx3] >tar)idx3--;
                else if(nums[idx1]+nums[idx2]+nums[idx3]<tar)idx2++;
            }
        }
        return sum;
    }
};