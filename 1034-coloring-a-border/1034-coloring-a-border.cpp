class Solution {
public:
    void dfs(int r,int c,int x,vector<vector<int>>&temp)
    {
        if(r>=temp.size() || r<0 || c>=temp[0].size() || c<0 || temp[r][c]!=x)return ;
        temp[r][c]=0;
        
        dfs(r+1,c,x,temp);
        dfs(r-1,c,x,temp);
        dfs(r,c+1,x,temp);
        dfs(r,c-1,x,temp);
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
          int n=grid.size();
          int m=grid[0].size();
        
        int x=grid[row][col];
        vector<vector<int>>temp=grid;        
        dfs(row,col,x,temp);
        
        
        for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
				{
					if (temp[i][j] == 0) grid[i][j] = color;
				}
				else
				{
					if (temp[i][j] == 0 && (temp[i + 1][j] != 0 || temp[i - 1][j] !=  0 || temp[i][j + 1]!=  0 || temp[i][j - 1]!=  0))
					{
						grid[i][j] = color;
					}
				}
			}
		}
		return grid;
    }
};