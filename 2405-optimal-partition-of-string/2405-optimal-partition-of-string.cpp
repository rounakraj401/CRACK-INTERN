class Solution {
public:
    int partitionString(string s) {
        set<char>st;
        int n=s.length();
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(st.count(s[i]))
            {
                ans++;
                st.clear();
            }
            st.insert(s[i]);
        }
        if(st.size()>0)ans++;
        return ans;
    }
};