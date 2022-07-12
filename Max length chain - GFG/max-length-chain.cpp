// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
int fun(int idx,vector<pair<int,int>>&v,int n,int prev,vector<vector<int>>&dp)
{
    if(idx==n)return 0;
    
    if(dp[idx][prev+1]!=-1)return dp[idx][prev+1];
    
    int nottake=fun(idx+1,v,n,prev,dp);
    int take=INT_MIN;
    if(prev==-1 || v[idx].first>v[prev].second)take=1+fun(idx+1,v,n,idx,dp);
    
    return dp[idx][prev+1]=max(take,nottake);
}

int maxChainLen(struct val p[],int n)
{
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++){
    v.push_back({p[i].first,p[i].second});
    }
    sort(v.begin(),v.end());
    
    vector<vector<int>>dp(n,vector<int>(n,-1));
    return fun(0,v,n,-1,dp);
}