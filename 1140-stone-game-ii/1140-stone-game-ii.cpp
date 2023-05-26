class Solution {
public:
    int dp[101][201];
    long long int fun(int idx,int m,vector<int>&piles)
    {
        if(idx>=piles.size())return 0;
        if(dp[idx][m]!=-1)
            return dp[idx][m];
        
        long long int sum=0;
        long long int ans=INT_MIN;
        for(int i=idx;i<idx+2*m && i<piles.size();i++)
        {
            sum+=piles[i];
            ans=max(ans,sum-fun(i+1,max(m,i-idx+1),piles));
        }
        return dp[idx][m]=ans;
    }
    
    int stoneGameII(vector<int>& piles) {
        long long int tot=0;
        memset(dp,-1,sizeof(dp));
        for(auto it:piles)
        {
            tot+=it;
        }
        long long int diff=fun(0,1,piles);
        long long int ans=(tot+diff)/2;
        
        return (int)ans;
    }
};