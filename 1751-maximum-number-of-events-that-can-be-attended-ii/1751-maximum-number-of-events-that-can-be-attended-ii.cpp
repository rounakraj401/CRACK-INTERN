// class Solution {
// public:
// //     int fun(int idx,vector<int>&vec,vector<vector<int>>&events,int k,vector<vector<int>>&dp)
// //     {
// //         if(idx>=events.size() || k<=0)return 0;
        
// //         if(dp[idx][k]!=-1)
// //             return dp[idx][k];
        
// //         int nottake=fun(idx+1,vec,events,k,dp);
// //         int temp=upper_bound(vec.begin(),vec.end(),events[idx][1])-vec.begin();
        
// //         int take=events[idx][2]+fun(temp,vec,events,k-1,dp);
        
// //         return dp[idx][k]=max(take,nottake);
// //     }

// memory limit exceeded for above solution
  
//     int maxValue(vector<vector<int>>& events, int k) {
//         vector<int> s;
//         for(auto i : events) s.push_back(i[0]);
//         sort(s.begin(), s.end());
        
//         sort(events.begin(), events.end(),  [](const vector<int>&a, const vector<int>&b){
//            return a[0] < b[0]; 
//         });
        
//         vector<vector<int>> dp(events.size()+1, vector<int>(k+1, 0));
//         int n = events.size();
//         for(int idx = n-1;idx >= 0;idx--){
//             for(int j = 1;j <= k;j++){
//                 int ntake = dp[idx+1][j];
//                 int nxt = upper_bound(s.begin(), s.end(), events[idx][1]) - s.begin();
//                 int take = events[idx][2] + dp[nxt][j-1];
//                 dp[idx][j] = max(take, ntake); 
//             }
//         }
//         return dp[0][k];
//     }
// };

class Solution {
public:
vector<vector<int>>dp;
//dp[n][k+1]
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin() , events.end());
        int n = events.size();
        dp.resize( n, vector<int>( k + 1, -1));
        return solve(events , 0 , k , 0);
    }
    int solve(vector<vector<int>>& events,int i, int k,int end){
        if(i==events.size() || k==0) return 0;
        
        if( events[i][0] <= end ) return solve( events, i + 1 , k , end );
        
        if( dp[i][k] != -1) return dp[i][k];
        
        int choices= max ( events[i][2] + solve(events, i + 1, k - 1 , events[i][1] ),  solve(events , i + 1 , k , end ) );
        return dp[i][k] = choices;
    }
};