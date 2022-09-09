class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
       if(a[0]!=b[0])
           return a[0]>b[0];
        return a[1]<b[1];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& pro)
    {
        int n=pro.size();
        int m=pro[0].size();
        
        int cnt=0;
        sort(pro.begin(),pro.end(),cmp);
        
        int maxm=INT_MIN;
        for(auto it:pro)
        {
            if(maxm>it[1])cnt++;
            else
                maxm=it[1];
        }
        return cnt;
    }
};