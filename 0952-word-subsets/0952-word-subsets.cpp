class Solution {
public:
    vector<int>give(string s)
    {
        vector<int>freq(26,0);
        for(int i=0;i<s.size();i++)
            freq[s[i]-'a']++;
        
        return freq;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int>maxfreq(26,0);
        vector<string>ans;
        for(auto it:words2)
        {
            vector<int>freq=give(it);
            
            for(int i=0;i<26;i++)maxfreq[i]=max(maxfreq[i],freq[i]);
        }
        
        for(auto it:words1)
        {
            bool flag=0;
            vector<int>freq=give(it);
            
            for(int i=0;i<26;i++)
            {
                if(freq[i]<maxfreq[i])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)ans.push_back(it);
        }
        return ans;
    }
};