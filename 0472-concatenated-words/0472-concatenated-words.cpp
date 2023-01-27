class Solution {
public:
    set<string>st;
    bool check(string s)
    {
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            string pref=s.substr(0,i);
            string suff=s.substr(i,n-i);
            
            if(st.count(pref)>0 && (st.count(suff)>0 ||  check(suff)))
               return true;
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