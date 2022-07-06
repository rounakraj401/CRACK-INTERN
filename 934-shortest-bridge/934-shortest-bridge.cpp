class Solution {
public:
    void dfs(vector<vector<int>>&grid,int i,int j)
    {
        if(i<0 || j<0 || i>=grid.size() ||j>=grid[0].size() || grid[i][j]!=1)return;
        
        grid[i][j]=-1;
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
    
    }
    bool check(vector<vector<int>>&grid,int i,int j)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==1)return false;
        
        grid[i][j]==0?grid[i][j]=1:grid[i][j]=-1;
        return true;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        
        bool flag=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)
                {
                 dfs(grid,i,j);
                 flag=1;
                 break;
                }
            }
            if(flag)break;
        }
        
        queue<vector<int>>q;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j,0});
                }
            }
        }
        
        while(!q.empty())
        {
            int siz=q.size();
            for(int k=0;k<siz;k++){
                
               auto it=q.front();
                int i=it[0];
                int j=it[1];
                int ans=it[2];
                
                q.pop();
                
                if(grid[i][j]==-1)return ans-1;
                
                if(check(grid,i+1,j))
                   q.push({i+1,j,ans+1});
                if(check(grid,i-1,j))
                   q.push({i-1,j,ans+1});
                if(check(grid,i,j+1))
                   q.push({i,j+1,ans+1});
                if(check(grid,i,j-1))
                   q.push({i,j-1,ans+1});
            }
        }
        return -1;
    }
};