class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans=0;
        
        int d=nums[nums.size()-1];
        
        int i=nums.size()-2;
        
        while(i>=0)
        {
            if(nums[i]<d)
            {
                d=min(d,nums[i]);
            }
            else
            {
                ans+=ceil(nums[i]/(double)d)-1;
                
                d=nums[i]/(ceil(nums[i]/(double)d));
                
      //          cout<<ans<<" "<<d<<"\n";
            }
            
            i--;
        }
        return ans;
    }
};