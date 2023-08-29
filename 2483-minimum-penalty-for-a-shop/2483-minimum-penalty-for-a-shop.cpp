class Solution {
public:
    int bestClosingTime(string s) {
        int cntY=0;
        int cntN=0;
        int n=s.size();
        
        for(auto it:s)
        {
            if(it=='Y')cntY++;
        }
        
        int temp=cntY,ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='N')
                cntN++;
            else
                cntY--;
            
            if(cntN+cntY<temp)
            {
                temp=cntN+cntY;
                ans=i+1;
            }
        }
        return ans;
    }
};