class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int st=0;
        int end=0;
        
        int l=0;
        int r=0;
        int ans=1;
        
        for(int i=0;i<n-1;i++)
        {
            l=i;
            r=i;
            while(l>=0 && r<n)
            {
                if(s[l]==s[r]){
                l--;
                r++;
            }
            else
                break;
            }
            int len=r-l-1;
            if(len>ans)
            {
                ans=len;
                st=l+1;
            }
        }
        
        for(int i=0;i<n-1;i++)
        {
            l=i;
            r=i+1;
            while(l>=0 && r<n){
             if(s[l]==s[r])
             {
                l--;
                r++;
             }
            else
                break;
            }
            
            int len=r-l-1;
            if(len>ans)
            {
                ans=len;
                st=l+1;
            }
        }
        string a=s.substr(st,ans);
        return a;
    }
};