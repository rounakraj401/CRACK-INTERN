class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ans;
        
        int n=words.size();
        int m=words[0].size();
        int t=m*n;
        
        if(s.size()<t)return ans;

        unordered_map<string,int>freq;
        for(auto it:words)
        {
            freq[it]++;
        }
        
        for(int i=0;i<s.size()-t+1;i++)
        {
            unordered_map<string,int>mp=freq;
            int j;
            for(j=0;j<s.size();j++)
            {
                string temp=s.substr(i+j*m,m);
                if(mp[temp]==0)
                    break;
                else
                    mp[temp]--;
            }
            
            if(j==n)
                ans.push_back(i);
        }
        
        return ans;
    }
};