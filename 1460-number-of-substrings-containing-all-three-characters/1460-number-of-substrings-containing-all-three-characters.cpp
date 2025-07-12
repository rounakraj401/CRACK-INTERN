class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int i=0;
        int j=0;
        int ans=0;
        unordered_map<char,int>mp;

        while(i<n)
        {
           mp[s[i]]++;
           while(mp['a'] && mp['b'] && mp['c'])
           {
              ans+=n-i;
              mp[s[j]]--;
              j++;
           }
           i++;
        }
        return ans;
    }
};