// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    string fun(int n)
    {
        string s="";
        while(n)
        {
            s=to_string(n%2)+s;
            n/=2;
        }
        return s;
    }
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        string s1=fun(a);
        string s2=fun(b);
        
        while(s1.size()<32)s1='0'+s1;
        while(s2.size()<32)s2='0'+s2;
        int ans=0;
        
 //       cout<<s1<<" "<<s2<<"\n";
        
        for(int i=0;i<32;i++)
        {
            if(s1[i]!=s2[i])ans++;
        }
        return ans;
    }
};

// { Driver Code Starts.

// Driver Code
int main()
{
	int t;
	cin>>t;// input the testcases
	while(t--) //while testcases exist
	{
		int a,b;
		cin>>a>>b; //input a and b

        Solution ob;
		cout<<ob.countBitsFlip(a, b)<<endl;
	}
	return 0;
}  // } Driver Code Ends