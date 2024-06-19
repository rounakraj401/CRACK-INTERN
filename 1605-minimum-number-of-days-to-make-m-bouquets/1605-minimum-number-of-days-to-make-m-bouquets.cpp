class Solution {
public:
    bool check(int mid,vector<int>&bloom,int m,int k)
    {
        int n=bloom.size();
        int cnt=0;
        int curr=0;
        for(int i=0;i<n;i++)
        {
            if(bloom[i]<=mid)
                curr++;
            else
                curr=0;
            
            if(curr==k)
            {
                cnt++;
                curr=0;
            }
        }
        
        if(cnt>=m)return true;
        return false;
    }
    int minDays(vector<int>& bloom, int m, int k) {
        int n=bloom.size();        
        int ans=-1;
        int mid;
        
        int l=1;
        int h=*max_element(bloom.begin(),bloom.end());
        
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(check(mid,bloom,m,k))
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