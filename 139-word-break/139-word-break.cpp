class Solution {
public:
//     bool fun(int idx,string s,unordered_set<string>&st,vector<int>&dp)
//     {
//         if(idx>=s.length())return 1;
        
//          if(dp[idx]!=-1)return dp[idx];
        
//         string cur="";
//         for(int i=idx;i<s.length();i++)
//         {
//             cur+=s[i];
//             if(st.count(cur))
//             {
//                 if(fun(i+1,s,st,dp))return dp[idx]=1;
//             }
//         }
//         return dp[idx]=0;
//     }
    bool wordBreak(string s, vector<string>& word) {
        unordered_set<string>st(word.begin(),word.end());
        // vector<int>dp(s.length()+1,-1);
        // return fun(0,s,st,dp);
        int n=s.length();
        vector<bool>dp(n+1,0);
        
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            string cur;
            for(int j=0;j<i;j++)
            {
                cur=s.substr(j, i-j);
                if(st.count(cur) && dp[j])
                {
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[n];
    }
};