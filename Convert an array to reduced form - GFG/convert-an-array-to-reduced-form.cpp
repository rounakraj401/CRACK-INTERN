//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	void convert(int arr[], int n) {
	    unordered_map<int,int>mp;

	    for(int i=0;i<n;i++)
	    {
	        mp[arr[i]]=i;
	    }
	    sort(arr,arr+n);
	    vector<int>temp(n);
	    int idx=0;
	    for(int i=0;i<n;i++)
	    {
	        temp[mp[arr[i]]]=idx;   
	        idx++;
	    }
	   // for(int i=0;i<n;i++)cout<<temp[i]<<" ";
	   // cout<<"\n";
	    for(int i=0;i<n;i++)
	      arr[i]=temp[i];
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.convert(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends