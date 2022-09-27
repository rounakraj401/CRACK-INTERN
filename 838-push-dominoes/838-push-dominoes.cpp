class Solution {
public:
    string pushDominoes(string dom) {
        int n=dom.size();
        vector<int>left(n,0),right(n,0);
        
        char prev='.';
        int cnt=1;
        
        for(int i=0;i<n;i++)
        {
            if(dom[i]=='R')
            {
                cnt=1;
                prev='R';
                continue;
            }
            else if(dom[i]=='L')
            {
                prev='L';
            }
            if(prev=='R' && dom[i]=='.')
            {
                right[i]=cnt;
                cnt++;
            }
        }
        prev='.';
        cnt=1;
        for(int i=n-1;i>=0;i--)
        {
            if(dom[i]=='L')
            {
                cnt=1;
                prev='L';
                continue;
            }
            else if(dom[i]=='R')
            {
                prev='R';
            }
            if(prev=='L' && dom[i]=='.')
            {
                left[i]=cnt;
                cnt++;
            }
        }
        
        string ans="";
        for(int i=0;i<n;i++)
        {
            if(left[i]==0 && right[i]==0)
                ans+=dom[i];
            else if(right[i]==0)
                ans+='L';
            else if(left[i]==0)
                ans+='R';
            else if(left[i]>right[i])
                ans+='R';
            else if(left[i]<right[i])
                ans+='L';
            else if(left[i]==right[i])
                ans+='.';
        }
        return ans;
    }
};