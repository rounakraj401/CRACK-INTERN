class Solution {
public:
    const int mod=1e9+7;
//     int fun(string s,int k,int idx)
//     {
//         if(idx==s.size())return 1;
        
//         int cur=0;
//         int ways=0;
        
//         for(int i=idx;i<s.size();i++)
//         {
//             cur=(cur*10)+(s[i]-'0');
//             if(cur<1 || cur>k)break;
            
//             int nextways=fun(s,k,i+1);
//             ways=(ways+nextways)%mod;
//         }
//         return ways;
//     }
    int numberOfArrays(string s, int k) {
        int idx=0;
        int n=s.size();
        vector<int>dp(n+1,0);
        
        dp[n]=1;
        
        for(int i=n-1;i>=0;i--)
        {
            long long int cur=0,ways=0;
            for(int j=i;j<s.size();j++)
            {
                cur=(cur*10)+(s[j]-'0');
                if(cur<1 || cur>k)break;
                
                int nextways=dp[j+1];
                ways=(ways+nextways)%mod;
            }
            dp[i]=ways;
        }
        return dp[0];
    }
};