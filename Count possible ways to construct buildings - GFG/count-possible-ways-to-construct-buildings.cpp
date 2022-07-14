// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	long long int mod=1e9+7;
	int fun(int i,int n,vector<int>&dp)
	{
	    if(i>=n)return 1;
	    if(dp[i]!=-1)return dp[i];
	    
	    return dp[i]=(fun(i+1,n,dp)%mod+fun(i+2,n,dp)%mod)%mod;
	}
	int TotalWays(int n)
	{
	    vector<int>dp(n+1,-1);
	    long long int ans=fun(0,n,dp);
	    return ((ans%mod)*(ans%mod)*1ll)%mod;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends