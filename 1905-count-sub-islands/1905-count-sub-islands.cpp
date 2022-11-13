class Solution {
public:
    void dfs(int i,int j,int n,int m,vector<vector<int>>&grid1,vector<vector<int>>&grid2,bool &flag)
    {
        if(i<0 || i>=n || j<0 || j>=m || grid2[i][j]==0)return;
        
        if(grid1[i][j]!=1)
            flag=0;
        
        grid2[i][j]=0;
        
        dfs(i+1,j,n,m,grid1,grid2,flag);
        dfs(i-1,j,n,m,grid1,grid2,flag);
        dfs(i,j+1,n,m,grid1,grid2,flag);
        dfs(i,j-1,n,m,grid1,grid2,flag);
        
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid2.size();
        int m=grid2[0].size();
        
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid2[i][j]==1)
                {
                    bool flag=1;
                    dfs(i,j,n,m,grid1,grid2,flag);
                    
                    if(flag==1)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};