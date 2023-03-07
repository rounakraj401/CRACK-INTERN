class Solution {
public:
    long long minimumTime(vector<int>& time, int k) {
        
        long long int l=1;
        long long int h=1e14;
        long long int ans;
        while(l<=h)
        {
            long long int mid=(l+h)/2;
            
            long long int tot=0;
            for(auto it:time)
                tot+=mid/it;
            
            if(tot>=k)
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