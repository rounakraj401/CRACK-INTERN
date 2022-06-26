class Solution {
public:
 //   int cnt=0;
    
    void dfs(vector<vector<int>>& grid,int i,int j,int n,int m,int &cnt)
    {
        if(i>=n || i<0 || j>=m || j<0)return ;
        if(grid[i][j]==0)return;
        
        grid[i][j]=0;
        cnt++;
        
        dfs(grid,i+1,j,n,m,cnt);
        dfs(grid,i-1,j,n,m,cnt);
        dfs(grid,i,j+1,n,m,cnt);
        dfs(grid,i,j-1,n,m,cnt);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1)
                dfs(grid,i,0,n,m,cnt);
            if(grid[i][m-1]==1)
                dfs(grid,i,m-1,n,m,cnt);
        }
        for(int i=0;i<m;i++)
        {
            if(grid[0][i]==1)
                dfs(grid,0,i,n,m,cnt);
            if(grid[n-1][i]==1)
                dfs(grid,n-1,i,n,m,cnt);
        }
        
        cnt=0;
        for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] == 1) {
				dfs(grid, i, j, n, m,cnt);
			}
		}
	}
        return cnt;
    }
};