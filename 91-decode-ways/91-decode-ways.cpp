class Solution {
public:
    int fun(int idx,int n,string&s,vector<int>&dp)
    {
        if(s[idx]=='0')return 0;
        if(idx>=n-1)return 1;
        
        if(dp[idx]!=-1)return dp[idx];
        
        int x1=fun(idx+1,n,s,dp);
        string temp=s.substr(idx,2);
        int x2=(stoi(temp)>=1 && stoi(temp)<=26)?fun(idx+2,n,s,dp):0;
        
        return dp[idx]=x1+x2;
        
    }
    int numDecodings(string s) {
        int n=s.length();
        vector<int>dp(101,-1);
        return fun(0,n,s,dp);
    }
};