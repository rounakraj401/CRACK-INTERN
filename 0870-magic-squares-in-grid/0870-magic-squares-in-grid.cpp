class Solution {
public:
    bool check(int i,int j,vector<vector<int>>& grid)
    {
            int col1 = grid[i][j] + grid[i+1][j] + grid[i-1][j];
            int col2 = grid[i-1][j-1] + grid[i][j-1] + grid[i+1][j-1];
            int col3 = grid[i-1][j+1] + grid[i][j+1] + grid[i+1][j+1];

            int row1 = grid[i][j] + grid[i][j+1] + grid[i][j-1];
            int row2 = grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j-1];
            int row3 = grid[i-1][j] + grid[i-1][j+1] + grid[i-1][j-1];

            int diag1 = grid[i][j] + grid[i+1][j+1] + grid[i-1][j-1];
            int diag2 = grid[i][j] + grid[i+1][j-1] + grid[i-1][j+1];

            if(row1==row2 && row1==row3 && col1==col2 && col1==col3 && diag1==diag2)
             return 1;
            return 0;
    }
    bool ismagic(int idx,int jdx,vector<vector<int>>& grid)
    {
         set<int>st;
         for(int i=idx-1;i<=idx+1;i++)
         {
            for(int j=jdx-1;j<=jdx+1;j++)
            {
                st.insert(grid[i][j]);
            }
         }
         for(int i=1;i<=9;i++)
         {
            if(st.count(i)==0)
             return 0;
         }
         
         if(check(idx,jdx,grid))return 1;
         return 0;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        if(n<3 || m<3)return 0;

        int ans=0;

        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<m-1;j++)
            {
                if(grid[i][j]==5)
                {
                    ans+=ismagic(i,j,grid);
                }
            }
        }
        return ans;
    }
};