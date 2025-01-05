class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int>vec(n+1,0);

      for(int i=0;i<shifts.size();i++)
       { 
          int s=shifts[i][0];
          int e=shifts[i][1];
          int dir=shifts[i][2];

        if(dir==1)
         {
            vec[s]++;
            vec[e+1]--;
         }
        else
         {
            vec[s]--;
            vec[e+1]++;
         }
       }

       int sum=0;
       for(int i=0;i<n;i++)
       {
         sum+=vec[i];
         int k=sum%26;
         int x=(s[i]-'a'+k+26)%26;
         s[i]=char('a'+x);
       }
       return s;
    }
};