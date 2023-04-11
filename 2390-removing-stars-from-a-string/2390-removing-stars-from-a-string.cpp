class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!='*')
                st.push(s[i]);
            else
                st.pop();
        }
        string ans(st.size(),'*');
        int i=st.size()-1;
        
        while(!st.empty())
        {
            ans[i--]=st.top();
            st.pop();
        }
        return ans;
    }
};