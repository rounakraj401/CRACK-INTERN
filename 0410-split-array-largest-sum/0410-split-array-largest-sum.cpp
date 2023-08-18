class Solution {
public:
    bool check(vector<int>&nums,int n,int m,int mid)
    {
        int sum=0;
        int i=0;
        while(i<n)
        {
            sum+=nums[i];
            if(sum>mid)
            {
                sum=nums[i];
                m--;
            }
            i++;
        }
        return m>=1;
    }
    int splitArray(vector<int>& nums, int m) {
        int n=nums.size();
        int l=*max_element(nums.begin(),nums.end());
        int h=0;
        for(int i=0;i<n;i++)h+=nums[i];
        
        int ans=h;
        while(l<=h)
        {
            int mid=(l+h)/2;
   //         cout<<l<<" "<<h<<" "<<mid<<"\n";
            if(check(nums,n,m,mid))
            {
                ans=mid;
                h=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};