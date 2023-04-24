class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int ans=0;
        
        int i=0;
        int j=0;
        int maxm=0;
        
        unordered_map<char,int>mp;
        while(j<n)
        {
           mp[s[j]]++;
           maxm=max(maxm,mp[s[j]]);
            
            if(j-i+1-maxm>k)
            {
                mp[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};