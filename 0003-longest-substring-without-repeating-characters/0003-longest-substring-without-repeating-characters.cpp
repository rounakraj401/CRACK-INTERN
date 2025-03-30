class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int i=0;
        int j=0;
        int n=s.size();
        map<char,int>mp;
        int temp=0;

        while(j<n)
        {
           mp[s[j]]++;

           while(mp[s[j]]==2)
           {
              mp[s[i]]--;
              i++;
           }
           ans=max(ans,j-i+1);
           j++;
        }
        ans=max(ans,j-i);
        return ans;
    }
};