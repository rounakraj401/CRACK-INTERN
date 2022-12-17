class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<long long int>st;
        
        for(int i=0;i<n;i++)
        {
            if(tokens[i]!="+" && tokens[i]!="*" && tokens[i]!="-" && tokens[i]!="/")
            {
                stringstream geek(tokens[i]);
                long long int x = 0;
                geek >> x;
                
                st.push(x);
            }
            else
            {
                long long int a=st.top();
                st.pop();
                long long int b=st.top();
                st.pop();
                
                if(tokens[i]=="+")
                {
                    st.push(a+b);
                }
                else if(tokens[i]=="*")
                {
                    st.push(a*b);
                }
                else if(tokens[i]=="-")
                {
                    st.push(b-a);
                }
                else if(tokens[i]=="/")
                {
                    st.push(b/a);
                }
                
 //               cout<<st.top()<<"\n";
            }
  //          cout<<st.top()<<"\n";
        }
        return st.top();
    }
};