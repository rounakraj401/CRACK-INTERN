//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
          int cnt=0;
          int n=s.size();
          int maxm=INT_MIN;
          if(n==1)
           return n;
          
          for(int i=0;i<=n/2;i++)
          {
              if(s.substr(0,i+1)==s.substr(i+1,i+1))
              {
                  maxm=max(maxm,i+1);
              }
          }
          return n-maxm+1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends