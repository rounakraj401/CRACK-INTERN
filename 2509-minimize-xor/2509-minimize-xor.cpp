
class Solution {
public:
    string numtostring(int num)
    {
        string s="";
        while(num)
        {
            int x=num%2;
            num/=2;
            s=to_string(x)+s;
        }
        while(s.size()!=31)
        {
            s='0'+s;
        }
        return s;
    }
    int stringtonum(string s)
    {
        int ans=0;
        int idx=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]=='1')ans+=(pow(2,idx));
            idx++;
        }
        return ans;
    }
    int minimizeXor(int num1, int num2) {
        string s=numtostring(num2);
        string ss=numtostring(num1);

        cout<<s<<" "<<ss<<"\n";
        int x;
        int cnt=0;
        for(auto it:s)
        {
            if(it=='1')cnt++;
        }
        cout<<cnt<<"\n";

        string ans;
        for(int i=0;i<ss.size();i++)
        {
            if(ss[i]=='1' && cnt>0)
            {
                ans.push_back('1');
                cnt--;
            }
            else
             ans.push_back('0');
        }
        cout<<ans<<" "<<"\n";
        cout<<ans.size()<<"\n";
        cout<<cnt<<"\n";

        int idx=ans.size()-1;
        while(idx>=0 && cnt>0)
        {
            cout<<ans[idx]<<"\n";
            if(ans[idx]=='0')
            {
                ans[idx]='1';
                cnt--;
            }
            idx--;
        }
         cout<<ans<<" "<<"\n";
        return stringtonum(ans);
    }
};
