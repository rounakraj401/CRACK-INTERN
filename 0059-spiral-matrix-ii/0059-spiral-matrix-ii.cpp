class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int rs=0;
        int re=n-1;
        int cs=0;
        int ce=n-1;
        vector<vector<int>>ans(n,vector<int>(n,0));
        int k=1;
        
        while(cs<=ce && rs<=re)
        {
            for(int i=cs;i<=ce;i++)
            {
                ans[rs][i]=k;
                k++;
            }
            rs++;
            
            for(int i=rs;i<=re;i++)
            {
                ans[i][ce]=k;
                k++;
            }
            ce--;
            
            for(int i=ce;i>=cs;i--)
            {
                ans[re][i]=k;
                k++;
            }
            re--;
            
            for(int i=re;i>=rs;i--)
            {
                ans[i][cs]=k;
                k++;
            }
            cs++;
        }
        return ans;
    }
};