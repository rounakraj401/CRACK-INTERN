class Solution {
public:
    int fun(vector<int>&arr,int i,int n,int k,vector<int>&dp)
    {
        if(i>=n)return 0;
        int maxm=INT_MIN;
        int maxi=INT_MIN;
        
        if(dp[i]!=-1)return dp[i];
        
        int len=0;
        for(int j=i;j<min(n,i+k);j++)
        {
            len++;
            maxi=max(maxi,arr[j]);
            
            int cost=len*maxi+fun(arr,j+1,n,k,dp);
            maxm=max(maxm,cost);
        }
        return dp[i]=maxm;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1,0);
 //       return fun(arr,0,n,k,dp);
        dp[n]=0;
        for(int i=n-1;i>=0;i--)
        {
          int maxm=INT_MIN;
          int maxi=INT_MIN;
        
            int len=0;
            for(int j=i;j<min(n,i+k);j++)
            {
            len++;
            maxi=max(maxi,arr[j]);
            
            int cost=len*maxi+dp[j+1];
            maxm=max(maxm,cost);
            }
          dp[i]=maxm;
        }
        
        return dp[0];
    }
};