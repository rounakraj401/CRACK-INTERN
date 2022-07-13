class Solution {
public:
    int fun(int k,int n,vector<vector<int>>&dp)
    {
        if(k==1 || n<2)return n;
        
        if(dp[n][k]!=-1)return dp[n][k];
        
        int l=1;
        int h=n;
        int minm=INT_MAX;
        while(l<=h)
        {
            int mid=(l+h)/2;
            int eggbr=fun(k-1,mid-1,dp);
            int eggnbr=fun(k,n-mid,dp);
            
            if(eggbr<eggnbr)l=mid+1;
            else
                h=mid-1;
            
            int temp=1+max(eggbr,eggnbr);
            minm=min(minm,temp);
        }
        return dp[n][k]=minm;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return fun(k,n,dp);
    }
};