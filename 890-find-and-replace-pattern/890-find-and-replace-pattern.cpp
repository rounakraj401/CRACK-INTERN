class Solution {
public:
    vector<int>allot(string s)
    {
        if(s.size()==0)return {};
        
        int idx=0;
        map<char,int>mp;
        vector<int>v;
        
        for(int i=0;i<s.size();i++)
        {
            if(mp.find(s[i])==mp.end())
            {
                mp.insert({s[i],++idx});
                v.push_back(mp[s[i]]);
            }
            else
            {
                v.push_back(mp[s[i]]);
            }
        }
        return v;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<int>pat=allot(pattern);
        vector<string>ans;
        
        for(int i=0;i<words.size();i++)
        {
            vector<int>temp=allot(words[i]);
            
            if(pat==temp)ans.push_back(words[i]);
        }
        return ans;
    }
};