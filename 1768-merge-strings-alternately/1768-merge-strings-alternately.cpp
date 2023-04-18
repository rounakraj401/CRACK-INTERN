class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0,j=0;
        int n=word1.size();
        int m=word2.size();
        
        string ans="";
        bool flag=1;
        while(i<n && j<m)
        {
            if(flag)
              ans+=word1[i++];
            else
                ans+=word2[j++];
            flag=!flag;
        }
        while(i<n)ans+=word1[i++];
        while(j<m)ans+=word2[j++];
        
        return ans;
    }
};