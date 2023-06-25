class Solution {
public:
    const int mod=1e9+7;
    int fun(vector<int>&loc,int st,int fi,int fuel,vector<vector<int>>&dp)
    {   
        if(dp[st][fuel]!=-1)
            return dp[st][fuel];
        
        int ans=0;
        if(st==fi)ans++;
        
        for(int i=0;i<loc.size();i++)
        {
            if(i!=st && abs(loc[i]-loc[st])<=fuel)
            {
                ans+=fun(loc,i,fi,fuel-abs(loc[i]-loc[st]),dp);
                ans%=mod;
            }
        }
        return dp[st][fuel]=ans%mod;
        
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        vector<vector<int>>dp(locations.size()+1,vector<int>(fuel+1,-1));
        return fun(locations,start,finish,fuel,dp);
    }
};