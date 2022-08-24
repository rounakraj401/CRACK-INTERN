class Solution {
public:
    int trap(vector<int>& a) {
        int ans=0;
        int n=a.size();
        int lm=0;
        int rm=0;
        
        int l=0;
        int r=n-1;
        
        while(l<=r)
        {
            if(a[l]<=a[r])
            {
                if(a[l]>=lm)
                    lm=a[l];
                else
                    ans+=lm-a[l];
                
                l++;
            }
            else
            {
                if(a[r]>=rm)
                    rm=a[r];
                else
                    ans+=rm-a[r];
                
                r--;
            }
        }
        
        return ans;
    }
};