class Solution {
public:
    string reverseVowels(string s) {
        int l=0;
        int h=s.length()-1;
        set<char>st={'a','e','i','o','u','A','E','I','O','U'};
        
        while(l<h)
        {
            if(st.count(s[l]))
            {
                if(st.count(s[h]))
                {
                    swap(s[l],s[h]);
                    l++;
                    h--;
                }
                else
                    h--;
            }
            else
                l++;
        }
        return s;
    }
};