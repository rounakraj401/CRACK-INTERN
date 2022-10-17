class Solution {
public:
    bool checkIfPangram(string sentence) {
        map<char,int>mp;
        int n=sentence.length();
        for(int i=0;i<n;i++)
        {
            mp[sentence[i]]++;
        }
        int cnt=0;
        for(auto it:mp)
        {
            if(it.second>0)cnt++;
        }
        return cnt==26;
    }
};