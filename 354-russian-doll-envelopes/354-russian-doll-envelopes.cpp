class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        if(a[0]==b[0])return a[1]>b[1];
        
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& env) {
      
        int n=env.size();
        sort(env.begin(),env.end(),cmp);
        vector<int>dp;
        
        for(int i=0;i<n;i++)
        {
            int idx=lower_bound(dp.begin(),dp.end(),env[i][1])-dp.begin();
            
            if(idx==dp.size())dp.push_back(env[i][1]);
            else
                dp[idx]=env[i][1];
        }
        
        return dp.size();
    }    
};