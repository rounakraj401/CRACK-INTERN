class Solution {
public:
    bool wordPattern(string pattern, string ss) {
        int n=pattern.size();
        vector<string>words;
        unordered_map<string,char>mp;
        vector<bool>taken(26,0);
        
        stringstream s(ss);
        string word;
        
        
        while (s >> word)
         words.push_back(word);
        
   //     for(int i=0;i<words.size();i++)cout<<words[i]<<"\n";
        
        if(words.size()!=pattern.size())
            return false;
        
        for(int i=0;i<n;i++)
        {
             if(mp.find(words[i])!=mp.end() && mp[words[i]]!=pattern[i] )
                return false;
             if(mp.find(words[i])==mp.end() && taken[pattern[i]-'a']==1)
                 return false;
            
             mp[words[i]]=pattern[i];
             taken[pattern[i]-'a']=1;
        }
        
        return true;
    }
};