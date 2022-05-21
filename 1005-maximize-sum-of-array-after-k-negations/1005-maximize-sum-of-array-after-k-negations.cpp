class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        
        int n=nums.size();
        int ans=0;
        bool flag=0;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0){
                flag=1;
            }
            else if(nums[i]<0)cnt++;
        }
        if(flag)
        {
            sort(nums.begin(),nums.end());
            int i=0;
            while(cnt>0 && k>0)
            {
                nums[i]=-nums[i];
                i++;
                cnt--;
                k--;
            }
            for(int i=0;i<n;i++)ans+=nums[i];
        }
        else
        {
            sort(nums.begin(),nums.end());
            int i=0;
            while(cnt>0 && k>0)
            {
                nums[i]=-nums[i];
                i++;
                cnt--;
                k--;
            }
            for(int i=0;i<n;i++)ans+=nums[i];
            
            if(k!=0)
            {
                sort(nums.begin(),nums.end());
                
                if(k%2==1)ans=ans-2*nums[0];
                    
            }
        }
        return ans;
    }
};