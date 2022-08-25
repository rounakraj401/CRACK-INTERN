class Solution {
public:
    bool canConstruct(string note, string mag) {
        map<char,int>mp;
        for(auto it:mag)
        {
            mp[it]++;
        }
        for(auto it:note)
        {
            if(mp[it]==0)return false;
            mp[it]--;
        }
        return true;
    }
};