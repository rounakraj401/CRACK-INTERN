class Solution {
public:
    int fun(int idx,vector<int>&days,vector<int>&costs,vector<int>&dp)
    {
        if(idx<0)return 0;
        if(dp[idx]!=-1)return dp[idx];
        
        int x=costs[0]+fun(idx-1,days,costs,dp);
        
        int y=costs[1];
        int yy=lower_bound(days.begin(),days.end(),days[idx]-6)-days.begin();
        y+=fun(yy-1,days,costs,dp);
        
        int z=costs[2];
        int zz=lower_bound(days.begin(),days.end(),days[idx]-29)-days.begin();
        z+=fun(zz-1,days,costs,dp);
        
        return dp[idx]=min({x,y,z});
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        sort(days.begin(),days.end());
        int n=days.size();
        vector<int>dp(n+1,-1);
        return fun(n-1,days,costs,dp);
    }
};