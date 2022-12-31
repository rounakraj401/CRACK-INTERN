class Solution {
public:
    
    void dfs(vector<vector<int>>& grid , int n,int m,int i,int j,int &ans,int cnt,int &empty)
    {
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==-1)return;
        if(grid[i][j]==2)
        {
            if(cnt==empty)ans++;
            return;
        }
        
        grid[i][j]=-1;
        
        dfs(grid,n,m,i+1,j,ans,cnt+1,empty);
        dfs(grid,n,m,i-1,j,ans,cnt+1,empty);
        dfs(grid,n,m,i,j+1,ans,cnt+1,empty);
        dfs(grid,n,m,i,j-1,ans,cnt+1,empty);
        
        grid[i][j]=0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int si,sj,ans=0,empty=1;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    si=i;
                    sj=j;
                }
                else if(grid[i][j]==0)
                {
                    empty++;
                }
            }
        }
                
        dfs(grid,n,m,si,sj,ans,0,empty);
        
        return ans;
        
    }
};