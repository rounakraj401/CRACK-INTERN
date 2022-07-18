class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int tar) {
        int n=mat.size();
        int m=mat[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                mat[i][j]+=mat[i][j-1];
            }
        }
        
        
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=i;j<m;j++)
            {
                unordered_map<int,int>mp;
                mp[0]++;
                int sum=0;
                
                for(int row=0;row<n;row++)
                {
                    int curr=mat[row][j];
                    if(i>0)curr-=mat[row][i-1];
                    sum+=curr;
                    
                    cnt+=mp[sum-tar];
                    mp[sum]++;
                }
            }
        }
        return cnt;
    }
};