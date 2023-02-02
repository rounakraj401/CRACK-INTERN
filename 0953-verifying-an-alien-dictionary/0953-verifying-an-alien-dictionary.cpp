class Solution {
public:
    
    bool check(string a,string b,unordered_map<char,int>mp)
    {
        int idx=0;
        while(idx<a.size() && a[idx]==b[idx])idx++;
        if(a.size()==idx)return true;
        if(b.size()==idx)return false;
        
        return mp[a[idx]]<mp[b[idx]];
    }
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int>mp;
        for(int i=0;i<order.size();i++)
        {
            mp[order[i]]=i;
        }
        
        for(int i=1;i<words.size();i++)
        {
            if(!check(words[i-1],words[i],mp))return false;
        }
        return true;
    }
};