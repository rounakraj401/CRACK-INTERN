class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_map<string,int>mp;
        for(auto it:ideas)
            mp[it]++;
        
        long long ans=0;
        vector<vector<int>>dp(26,vector<int>(26,0));
        
        for(auto it:ideas)
        {
            char ch1=it[0];
            for(int j=0;j<26;j++)
            {
                it[0]=j+'a';
                if(mp.find(it)==mp.end())
                {
                    dp[ch1-'a'][j]++;
                }
            }
        }
        
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                ans+=dp[i][j]*dp[j][i];
            }
            //    cout<<dp[i][j]<<" ";
        //    cout<<"\n";
        }
        return ans;
    }
};