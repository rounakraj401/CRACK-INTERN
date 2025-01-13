class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>mp;
        int n=s.size();
        for(auto it:s)
        {
            mp[it]++;
        }
        for(auto it:mp)
        {
            int freq=it.second;
            if(freq>2)
            {
                if(freq%2==1)freq--;
                else
                 freq-=2;

                n-=freq;
            }
        }
        return n;
    }
};