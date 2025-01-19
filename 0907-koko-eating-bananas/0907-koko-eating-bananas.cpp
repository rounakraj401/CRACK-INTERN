class Solution {
public:
    bool check(vector<int>&piles,int mid,int h)
    {
        int n=piles.size();
        long long int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=(ceil)(piles[i]/(double)mid);
        }
        if(sum<=h)return true;
        else
            return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        int ans;
        while(l<=r)
        {
             int mid=(l+r)/2;
             if(check(piles,mid,h)){
                 ans=mid;
                 r=mid-1;
             }
            else
                l=mid+1;
        }
        return ans;
    }
};