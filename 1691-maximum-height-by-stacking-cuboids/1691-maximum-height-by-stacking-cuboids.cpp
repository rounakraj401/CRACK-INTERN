class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        if(a[0]<b[0])return true;
        else if(a[0]==b[0])
        {
            if(a[1]<b[1])return true;
            else if(a[1]==b[1])
            {
                if(a[2]<b[2])return true;
                return false;
            }
        }
        return false;
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        int n=cuboids.size();
        for(int i=0;i<n;i++)
        {
            sort(cuboids[i].begin(),cuboids[i].end());
        }
        sort(cuboids.begin(),cuboids.end(),cmp);
        
        vector<int>len(n+1,0);
        for(int i=0;i<n;i++)
        {
            len[i]=cuboids[i][2];
            for(int j=0;j<i;j++)
            {
                if(cuboids[i][0]>=cuboids[j][0] && cuboids[i][1]>=cuboids[j][1] && cuboids[i][2]>=cuboids[j][2] && len[i]<len[j]+cuboids[i][2] )
                    len[i]=len[j]+cuboids[i][2];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)ans=max(ans,len[i]);
        return ans;
    }
};