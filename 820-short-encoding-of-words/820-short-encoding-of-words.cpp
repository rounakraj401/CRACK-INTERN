class Solution {
public:
    static bool cmp(string &a ,string &b)
    {
        return a.length()>b.length();
    }
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        
        string ans="";
        for(string &it:words)
        {
            if(ans.find(it+"#")==string::npos)ans+=it+"#";
        }
        return ans.size();
    }
};