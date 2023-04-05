class Solution {
public:
    #define ll long long 
    bool check(ll mid,vector<int>&temp)
    {
        ll n=temp.size();
        ll add=0;
        
        for(ll i=n-1;i>0;i--)
        {
            if((ll)temp[i]+add>mid)
                add=(temp[i]+add-mid);
            else
                add=0;
        }
        if(temp[0]+add<=mid)
            return true;
        return false;
    }
    
    int minimizeArrayValue(vector<int>& nums) {
        ll n=nums.size();
        ll l=nums[0];
        ll h=*max_element(nums.begin(),nums.end());
        ll ans;
        
        while(l<=h)
        {
            ll mid=(l+h)/2;
     //       cout<<mid<<"\n";
            vector<int>temp=nums;
            if(check(mid,temp))
            {
                ans=mid;
                h=mid-1;
            }
            else
                l=mid+1;
        }
        return (int)ans;
    }
};