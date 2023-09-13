class Solution {
public:
    int candy(vector<int>& rat) {
        int n=rat.size();
        vector<int>ans(n,1);
        
        if(n==1)return 1;
        
 //       if(rat[0]>rat[1])ans[0]=ans[1]+1;
        
        for(int i=1;i<n;i++)
        {
            if(rat[i]>rat[i-1])ans[i]=ans[i-1]+1;
        }
        
//        if(rat[n-1]>rat[n-2])ans[n-1]=ans[n-2]+1;
        
        for(int i=n-2;i>=0;i--)
        {
            if(rat[i]>rat[i+1] && ans[i]<=ans[i+1])ans[i]=ans[i+1]+1;
        }
        
        int res=accumulate(ans.begin(),ans.end(),0);
        return res;
    }
};