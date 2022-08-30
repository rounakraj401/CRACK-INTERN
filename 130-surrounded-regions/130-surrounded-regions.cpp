class Solution {
public:
    void dfs(vector<vector<char>>&board,int i,int j)
    {
        if(i<0 ||j<0 ||i>=board.size() || j>=board[0].size() || board[i][j]!='O')
             return;
        
        board[i][j]='U';
        
        dfs(board,i,j+1);
        dfs(board,i,j-1);
        dfs(board,i+1,j);
        dfs(board,i-1,j);
        
    }
    void solve(vector<vector<char>>& board) {
        int n=(int)board.size();
        int m=(int)board[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || i==n-1 || j==0 || j==m-1)
                {
                    if(board[i][j]=='O')
                    {
                        dfs(board,i,j);
                    }
                }
            }
        }

        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]!='U')
                    board[i][j]='X';
                else
                    board[i][j]='O';
            }
        }
        return;
    }
};