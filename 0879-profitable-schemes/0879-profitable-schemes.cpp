class Solution {
public:
    int dp[102][102][102];
    int mod=1e9+7;
    // i->index for traversing both arrays
    // j->no of members in current group
    // k->total profit till now
    
    int fun(int i,int j,int k,int n,int minm,vector<int>&group,vector<int>&profit)
    {
        if(i==profit.size())
        {
            if(k>=minm && n>=j)return 1;
            return 0;
        }
        else if(j>n)return 0;
        
        if(dp[i][j][k]!=-1)
            return dp[i][j][k];
        
        int nottake=fun(i+1,j,k,n,minm,group,profit)%mod;
        int take=fun(i+1,j+group[i], min(minm,k+profit[i]) ,n,minm,group,profit)%mod;
        
        return dp[i][j][k]=(nottake%mod +take%mod)%mod;
    }
    
    int profitableSchemes(int n, int minm, vector<int>& group, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        return fun(0,0,0,n,minm,group,profit);
    }
};