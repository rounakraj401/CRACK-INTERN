class Solution {
public:
    int fun(int r,int c,int n,int m,vector<vector<int>>&grid)
    {
        if(r==n)return c;
        if(c==0 && grid[r][c]==-1)return -1;
        if(c==m-1 && grid[r][c]==1)return -1;
        
        if(grid[r][c]==1 && grid[r][c+1]==1)
        {
           return fun(r+1,c+1,n,m,grid);
        }
        if(grid[r][c]==-1 && grid[r][c-1]==-1)
        {
           return fun(r+1,c-1,n,m,grid);
        }
        return -1;
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int>ans;
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=0;i<m;i++)
        {
            ans.push_back(fun(0,i,n,m,grid));
        }
        return ans;
    }
};