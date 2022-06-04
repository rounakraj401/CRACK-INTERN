class Solution {
public:
//     bool issafe(int row,int col,vector<string>&board,int n)
//     {
//          int r=row;
//          int c=col;
        
//          while(row>=0 && col>=0)
//          {
//              if(board[row][col]=='Q')return false;
//              row--;
//              col--;
//          }
//          row=r;
//          col=c;
//          while(col>=0)
//          {
//              if(board[row][col]=='Q')return false;
//              col--;
//          }
//         col=c;
//         while(row<n && col>=0)
//         {
//             if(board[row][col]=='Q')return false;
//             row++;
//             col--;
//         }
//         return true;
//     }
    void solve(int col,vector<string>&board,vector<vector<string>>&ans,vector<int>&row,vector<int>&upperdag,vector<int>&lowerdag,int n)
    {
        
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(row[i]==0 && upperdag[n-1+col-i]==0 && lowerdag[col +i]==0)
            {
                row[i]=1;
                upperdag[n-1-i+col]=1;
                lowerdag[col+i]=1;
                
                board[i][col]='Q';
                solve(col+1,board,ans,row,upperdag,lowerdag,n);
                
                board[i][col]='.';
                row[i]=0;
                upperdag[n-1-i+col]=0;
                lowerdag[col+i]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
            board[i]=s;
        
        vector<int>row(n,0);
        vector<int>upperdag(2*n-1,0);
        vector<int>lowerdag(2*n-1,0);
        
        solve(0,board,ans,row,upperdag,lowerdag,n);
        return ans;
    }
};