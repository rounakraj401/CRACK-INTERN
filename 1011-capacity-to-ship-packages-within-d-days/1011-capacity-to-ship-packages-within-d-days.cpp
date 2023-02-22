class Solution {
public:
    bool check(int mid , vector<int>& weights, int days)
    {
        int cnt=1;int sum=0;
        int n=weights.size();
        for(int i=0;i<n;i++)
        {
            sum+=weights[i];
            if(sum>mid)
            {
                cnt++;
                sum=weights[i];
            }
        }
        if(cnt<=days)return true;
        else
            return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int l=*max_element(weights.begin(),weights.end());
        int s=0;
        for(int i=0;i<weights.size();i++)s+=weights[i];
        int h=s;
        int temp;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
        
            if(check(mid,weights,days))
            {
                temp=mid;
                h=mid-1;
            }
            else
                l=mid+1;
        }
        return temp;
        
    }
};