class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.size();
        set<char>st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        
        int cnt=0;
        int ans=0;
        
        for(int i=0;i<k;i++)
        {
           if(st.count(s[i]))
               cnt++;
        }
        ans=max(ans,cnt);
        for(int i=k;i<n;i++)
        {
            if(st.count(s[i]))cnt++;
            if(st.count(s[i-k]))cnt--;
            
            ans=max(ans,cnt);
        }
        return ans;
    }
};