class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    
    bool isvalid(int i,int j,int n,int m)
    {
        if(i<0 || i>=n || j<0 || j>=m)
            return false;
        
        return true;
    }
    bool dfs(int i,int j,int idx,int n,int m,vector<vector<char>>&board,string &word)
    {
        if(idx==word.size())
            return true;
        if(!isvalid(i,j,n,m))
            return false;
        
        if(board[i][j]==word[idx])
        {
            char temp=board[i][j];
            board[i][j]='0';
            
            for(int k=0;k<4;k++)
            {
                int newi=i+dx[k];
                int newj=j+dy[k];
                
                if(dfs(newi,newj,idx+1,n,m,board,word))
                        return true;
            }
            board[i][j]=temp;
        }
         return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
                
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    if(dfs(i,j,0,n,m,board,word))
                        return true;
                }
            }
        }
        return false;
    }
};