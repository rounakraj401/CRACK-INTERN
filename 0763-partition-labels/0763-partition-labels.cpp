class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.length();
        vector<int>ans;
        unordered_map<char,int>mp;
        set<int>st;
        int prev=0;
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        
        for(int i=0;i<n;i++)
        {
            if(st.find(s[i])==st.end())
                st.insert(s[i]);
            
            mp[s[i]]--;
            
            if(mp[s[i]]==0)
                st.erase(s[i]);
            
            if(st.empty())
            {
                ans.push_back(i+1-prev);
                prev=i+1;
            }
        }
        return ans;
    }
};