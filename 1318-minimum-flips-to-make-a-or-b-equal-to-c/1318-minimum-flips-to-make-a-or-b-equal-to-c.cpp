class Solution {
public:
    string fun(int n)
    {
        string s="";
        while(n)
        {
            s=to_string(n%2)+s;
            n/=2;
        }
        return s;
    }
    int minFlips(int a, int b, int c) {
        string s1=fun(a);
                string s2=fun(b);
                string s3=fun(c);
        
        while(s1.size()<32)s1='0'+s1;
        while(s2.size()<32)s2='0'+s2;
        while(s3.size()<32)s3='0'+s3;
        
        cout<<s1<<" "<<s2<<" "<<s3<<"\n";
        int ans=0;
        for(int i=0;i<32;i++)
        {
            if(s3[i]=='1')
            {
                if(s1[i]=='0' && s2[i]=='0')ans++;
            }
            else if(s3[i]=='0')
            {
                if(s1[i]=='1')ans++;
                if(s2[i]=='1')ans++;
            }
        }
        return ans;
    }
};