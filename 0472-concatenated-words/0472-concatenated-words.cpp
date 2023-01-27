class Solution {
public:
    set<string>st;
    unordered_map<string,int>mp;
    
    bool check(string s)
    {
        int n=s.size();
        if(mp.find(s)!=mp.end())return true;
        
        for(int i=0;i<n;i++)
        {
            string pref=s.substr(0,i);
            string suff=s.substr(i,n-i);
            
            if(st.count(pref)>0 && (st.count(suff)>0 ||  check(suff)))
            {
               mp[s]=1;
               return true;
            }
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(auto it:words)
        {
            st.insert(it);
        }
        vector<string>ans;
        for(auto it:words)
        {
            if(check(it))
                ans.push_back(it);
        }
        return ans;
    }
};