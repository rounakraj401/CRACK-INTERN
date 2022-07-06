class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        if(trust.size()==0 && n==1)return 1;
        
       vector<int>vec(n+1,0);
        for(int i=0;i<trust.size();i++)
        {
            vec[trust[i][1]]++;
            vec[trust[i][0]]--;
        }
        for(int i=1;i<=n;i++)if(vec[i]==n-1)return i;
        return -1;
    }
};