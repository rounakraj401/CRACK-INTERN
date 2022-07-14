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
        vector<int>dp(s.length()+1,0);
   //     return fun(0,s,st,dp);
        
        int l = s.length();
        
        string cs = "";
        dp[0] = 1;
        
        for(int i = 1 ; i<= l; i++){
            cs = "";
            for(int j = i ; j >= 1 ;j--){
                cs = s[j - 1] + cs ;
                if(st.count(cs) && dp[j - 1]){
                    dp[i] = 1;
                    break;
                }
            }            
        }

        return dp[l];
    }
};