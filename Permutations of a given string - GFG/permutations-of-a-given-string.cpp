// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	void solve(string &S,int idx,vector<string>&ans)
	{
	    if(idx==S.length())
	    {
	        ans.push_back(S);
	        return;
	    }
	    for(int i=idx;i<S.length();i++)
	    {
	        swap(S[idx],S[i]);
	        solve(S,idx+1,ans);
	        swap(S[idx],S[i]);
	    }
	}
		vector<string>find_permutation(string S)
		{
		    vector<string>ans;
		     solve(S,0,ans);
		    
		    set<string>st;
		    for(auto it:ans)st.insert(it);
		    
		    vector<string>temp;
		    for(auto it:st)temp.push_back(it);
		    
		    return temp;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends