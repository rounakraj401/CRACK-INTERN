class Solution {
public:
    int calculate(string s) {
        s+='+';
        
        char sign='+';
        int ans=0;
        int curr=0;
        stack<int>st;
        
        
        for(int i=0;i<s.size();i++)
        {
            if(isdigit(s[i])) curr = curr*10 + (s[i]-'0');
            
            else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
            {
                if(sign=='+')
                    st.push(curr);
                else if(sign=='-')
                {
                    st.push(-1*(curr));
                }
                else if(sign=='*')
                {
                    int x=st.top();
                    st.pop();
                    st.push(x*curr);
                }
                else if(sign=='/')
                {
                    int x=st.top();
                    st.pop();
                    st.push(x/curr);
                }
                
                curr=0;
                sign=s[i];
            }
        }
            while(!st.empty())
            {
   //            cout<<st.top();
                ans+=st.top();
                st.pop();
            }
            
            return ans;
    }
};