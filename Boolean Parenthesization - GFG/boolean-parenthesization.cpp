// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
#define ll long long
int mod=1003;
class Solution{
public:
int solve(int i, int j, int isTrue, string& exp, vector<vector<vector<ll>>>& dp){
    if(i>j) return 0;
    if(i==j) {
        if(isTrue)
            return exp[i] == 'T';
        else return exp[i] == 'F';
    }
    
    if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
    
    ll ways = 0;
    for(int ind=i+1;ind<=j-1;ind+=2){
        ll lT = solve(i, ind-1, 1, exp, dp);
        ll lF = solve(i, ind-1, 0, exp, dp);
        ll rT = solve(ind+1, j, 1, exp, dp);
        ll rF = solve(ind+1, j, 0, exp, dp);
        
        if(exp[ind]=='&'){
            if(isTrue)
                ways = (ways + (lT*rT)%mod)%mod;
            else 
                ways = (ways + (lT*rF)%mod + (rT*lF)%mod + (rF*lF)%mod)%mod;
        }
        else if(exp[ind]=='|'){
            if(isTrue)
                ways = (ways + (lT*rT)%mod + (lT*rF)%mod + (lF*rT)%mod)%mod;
            else
                ways = (ways + (lF*rF)%mod)%mod;
        }
        else {
            if(isTrue)
                ways = (ways + (lT*rF)%mod + (lF*rT)%mod)%mod;
            else
                ways = (ways + (lT*rT)%mod + (lF*rF)%mod)%mod;
        }
    }
    return dp[i][j][isTrue] = ways;
}
    int countWays(int n, string S){
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));
        return solve(0,n-1,1,S,dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends