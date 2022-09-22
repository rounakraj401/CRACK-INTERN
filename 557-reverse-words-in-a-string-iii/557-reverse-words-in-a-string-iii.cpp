class Solution {
public:
    string reverseWords(string s) {
        string word;
        string s1="";
        stringstream ss(s);
        while(ss>>word)
        {
            reverse(word.begin(),word.end());
            s1+=word+" ";
        }
        s1.pop_back();
        return s1;
    }
};