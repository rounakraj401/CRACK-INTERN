class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_multiset<int>st1;
        unordered_multiset<int>st2;
        
        unordered_set<char>s1;
        unordered_set<char>s2;
        
        map<char,int>mp1,mp2;
        for(auto it:word1)
        {
            mp1[it]++;
            s1.insert(it);
        }
        for(auto it:word2)
        {
            mp2[it]++;
            s2.insert(it);
        }
        
        for(auto it:mp1)
            st1.insert(it.second);
       for(auto it:mp2)
            st2.insert(it.second);
        
        return st1==st2 && s1==s2;
    }
};