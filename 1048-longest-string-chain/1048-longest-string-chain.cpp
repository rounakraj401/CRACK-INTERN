class Solution {
public:
    static bool compare(string s1,string s2)
    {
       if(s1.length()!=s2.length()+1)return false;
        
        int it1=0;
        int it2=0;
        
        while(it1<s1.size())
        {
             if(it2<s2.size() && s1[it1]==s2[it2])
             {
                 it1++;
                 it2++;
             }
            else
            {
                it1++;
            }
        }
        if(it1==s1.length() && it2==s2.length())return true;
        else
                return false;
        
    }
    static bool cmp(string a,string b)
    {
        return a.length()<b.length();
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<int>dp(n,1);
        
        sort(words.begin(),words.end(),cmp);
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(compare(words[i],words[j]))
                {
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};