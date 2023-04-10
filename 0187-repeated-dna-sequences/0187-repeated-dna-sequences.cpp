class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.length();
        unordered_map<string,int>mp;
        for(int i=0;i<=n-10;i++)
        {
            string ss=s.substr(i,10);
            mp[ss]++;
        }
        vector<string>ans;
        for(auto it:mp)
        {
            if(it.second>1)
                ans.push_back(it.first);
        }
        return ans;
    }
};