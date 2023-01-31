class Solution {
public:
    int dp[1002][1002];
    int fun(int idx,int n,int maxm,vector<vector<int>>&vec)
    {
        if(idx==n)return 0;
       
        if(dp[idx][maxm]!=-1)return dp[idx][maxm];
        
        if(vec[idx][1]>=maxm)
        {
           return dp[idx][maxm]=max(vec[idx][0]+fun(idx+1,n,vec[idx][1],vec) , fun(idx+1,n,maxm,vec));
        }
        return dp[idx][maxm]=fun(idx+1,n,maxm,vec);
    }
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n=ages.size();
        vector<vector<int>>vec;
        memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<n;i++)
        {
            vec.push_back({scores[i],ages[i]});
        }
        sort(vec.begin(),vec.end());
        
        return fun(0,n,0,vec);
    }
};