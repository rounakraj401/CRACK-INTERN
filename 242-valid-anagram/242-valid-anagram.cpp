class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size()!=t.size())return false;
        
       vector<int> a(26,0);
    for(int i=0;i<s.length();i++)
    {
        a[s[i]-'a']++;
        a[t[i]-'a']--;
    }
    
    for(auto ele :a)
        if(ele!=0)return 0;
    
    return 1;
    }
};