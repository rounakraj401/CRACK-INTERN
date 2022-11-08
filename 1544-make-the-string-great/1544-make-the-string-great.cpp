class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        int n=s.length();
        
        for(int i=0;i<n;i++)
        {
            if(st.empty())
                st.push(s[i]);
            else if(s[i]!=st.top() && (st.top()==tolower(s[i]) || st.top()==toupper(s[i])))
            {
                st.pop();
            }
            else
                st.push(s[i]);
        }
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};