class Solution {
public:
    string breakPalindrome(string palin) {
        vector<int>vec(26,0);
        int n=palin.size();
        
        for(int i=0;i<n;i++)
        {
            vec[palin[i]-'a']++;
        }
        if(n==1)return "";
        
        int cnt=0;
        for(int i=0;i<26;i++)
        {
            if(vec[i]>0)
            {
                cnt++;
            }
        }
          
        if(cnt==1)
        {
            if(palin[0]=='a')
                palin[n-1]='b';
            else 
                palin[0]='a';
            
            return palin;
        }
        
        if(cnt==2)
        {
            int cnt1=0;
            int cnt2=0;
            
            for(int i=0;i<26;i++)
            {
                if(vec[i] && cnt1==0)cnt1=vec[i];
                else if(vec[i] && cnt1!=0)cnt2=vec[i];
            }
            
            if(cnt1==1 || cnt2==1)
            {
             if(palin[0]=='a')
                palin[n-1]='b';
             else
                palin[0]='a';
            
             return palin;
            }
        }
        
         for(int i=0;i<n;i++)
         {
            if(palin[i]!='a'){
                palin[i]='a';
                break;
            }
         }
        return palin;
    }
};