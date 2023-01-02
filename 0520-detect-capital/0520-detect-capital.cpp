class Solution {
public:
    bool detectCapitalUse(string word) {
        string s1=word;
        transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
        
        if(s1==word)
            return true;
        
        string s2=word;
        transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
        
        if(s2==word)
            return true;
        
        for(int i=0;i<word.size();i++)
        {
            if(i==0)
            {
                if(word[i]!=toupper(s2[i]))
                    return false;
            }
            else
            {
                if(word[i]!=s2[i])return false;
            }
        }
        return true;
    }
};