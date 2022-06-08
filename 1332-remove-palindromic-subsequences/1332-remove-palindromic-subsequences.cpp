class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.size()==0)return 0;
        string s1=s;
        reverse(s.begin(),s.end());
        if(s1==s)return 1;
        else
            return 2;
    }
};