class Solution {
public:
//     int solve(vector<int>&cuts,int i,int j,vector<vector<int>>&dp)
//     {
//         if(i>j)return 0;
//         if(dp[i][j]!=-1)return dp[i][j];
        
//         int minm=INT_MAX;
//         for(int k=i;k<=j;k++)
//         {
//             minm=min(minm,cuts[j+1]-cuts[i-1]+solve(cuts,i,k-1,dp)+solve(cuts,k+1,j,dp));
//         }
//         return dp[i][j]=minm;
//     }
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        cuts.push_back(n);
        cuts.push_back(0);
        vector<vector<int>>dp(c+2,vector<int>(c+2,0));
        sort(cuts.begin(),cuts.end());
        
//        return solve(cuts,1,c,dp);
        
        for(int i=c;i>=1;i--)
        {
            for(int j=1;j<=c;j++)
            {
                if(i>j)continue;
                
                int minm=INT_MAX;
                for(int k=i;k<=j;k++)
                {
                    minm=min(minm,cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j]);
                }
                dp[i][j]=minm;
            }
        }
        return dp[1][c];
    }
};