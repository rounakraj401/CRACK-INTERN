class Solution {
public:
    int minDeletions(string s) {
          int n=s.length();
         unordered_map<int,int>m1;
         unordered_map<int,int>m2;
        
        for(int i=0;i<n;i++)
        {
            m1[s[i]-'a']++;
        }
        int cnt=0;
        for(auto it:m1)
        {
            int x=it.second;
            if(m2[x]!=0)
            {
                while(x>0 && m2[x]!=0)
                {
                    x--;
                    cnt++;
                }
            }
            if(x>0)
            {
                m2[x]++;
            }
        }
        return cnt;
    }
};