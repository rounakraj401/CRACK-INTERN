class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int>ss;
        int size=s.size();
        int l=0;
        int r=0;
        
        int ans=0;
        
        while(l<size && r<size)
        {
            if(ss.find(s[r])==ss.end())
            {
                ss.insert(s[r]);
                r++;
                int n=ss.size();
                ans=max(ans,n);
            }
            else
            {
                ss.erase(s[l]);
                l++;
            }
        }
        return ans;
    }
};