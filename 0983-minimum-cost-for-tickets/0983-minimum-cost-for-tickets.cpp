class Solution {
public:
//     int fun(int idx,vector<int>&days,vector<int>&costs,vector<int>&dp)
//     {
//         if(idx<0)return 0;
//         if(dp[idx]!=-1)return dp[idx];
        
//         int x=costs[0]+fun(idx-1,days,costs,dp);
        
//         int y=costs[1];
//         int yy=lower_bound(days.begin(),days.end(),days[idx]-6)-days.begin();
//         y+=fun(yy-1,days,costs,dp);
        
//         int z=costs[2];
//         int zz=lower_bound(days.begin(),days.end(),days[idx]-29)-days.begin();
//         z+=fun(zz-1,days,costs,dp);
        
//         return dp[idx]=min({x,y,z});
//     }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(367,0);
  //      return fun(n-1,days,costs,dp);
        
        for(auto it:days)
        {
            dp[it]=costs[0];
        }
        
        for(int i=1;i<=366;i++)
        {
            if(!dp[i])dp[i]=dp[i-1];
            else{            
               
                dp[i]=costs[0]+dp[i-1];
                dp[i]=min(dp[i] , costs[1]+dp[max(0,i-7)]);
                dp[i]=min(dp[i] , costs[2]+dp[max(0,i-30)]);
            }
        }
        return dp[days[n-1]];
    }
};