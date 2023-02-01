class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string ans="";
        int n1=str1.length();
        int n2=str2.length();
        
        int gcdd=__gcd(n1,n2);
        string temp=str1.substr(0,gcdd);
        
        for(int i=0;i<n1;i+=gcdd)
        {
            string ss=str1.substr(i,gcdd);
            if(ss!=temp)
                return ans;
        }
        for(int i=0;i<n2;i+=gcdd)
        {
            string ss=str2.substr(i,gcdd);
            if(ss!=temp)
                return ans;
        }
        return temp;
    }
};