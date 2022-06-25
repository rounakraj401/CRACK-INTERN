class Solution {
public:
    int dfs(vector<vector<int>>& grid,int i,int j)
    {
        if(i<0 || j<0 ||i>=grid.size() || j>=grid[0].size() || grid[i][j]==0)
            return 0;
        
        grid[i][j]=0;
        
        return (1+dfs(grid,i+1,j)+dfs(grid,i-1,j)+dfs(grid,i,j+1)+dfs(grid,i,j-1));
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=INT_MIN;;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    ans=max(ans,dfs(grid,i,j));
            }
        }
        if(ans==INT_MIN)return 0;
        return ans;
    }
};