class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char,int>mp;
        for(auto it:s)
        {
            mp[it]++;
        }
        int cnt=0;
        for(auto it:mp)
        {
            if(it.second%2==1)cnt++;
        }
        if(cnt<=k && k<=s.size())return true;
        return false;
    }
};