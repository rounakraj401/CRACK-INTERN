class Solution {
public:
    vector<int>dx={-1,1,0,0};
    vector<int>dy={0,0,1,-1};

    bool isValid(int x,int y , vector<vector<char>>&board)
    {
        int n=board.size();
        int m=board[0].size();

        if(x<0 || x>=n || y<0 || y>=m)return false;
        return true;
    }

    void bfs(int x,int y , vector<vector<char>>&board , vector<vector<int>>&vis)
    {
        queue<pair<int,int>>pq;
        pq.push({x,y});
      //  cout<<"om\n";

        while(!pq.empty())
        {
            int x=pq.front().first;
            int y=pq.front().second;
            
            pq.pop();
            vis[x][y]=1;

            for(int i=0;i<4;i++)
            {
                    int newx=x+dx[i];
                    int newy=y+dy[i];

                    if(isValid(newx,newy,board) && board[newx][newy]=='X' && vis[newx][newy]==0)
                    {
                        pq.push({newx,newy});
                    }
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int cnt=0;
        queue<pair<int,int>>pq;

        int n=board.size();
        int m=board[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='X' && vis[i][j]==0)
                 {
                    cnt++;
                    bfs(i,j,board,vis);
                 }
            }
        }

        return cnt;
    }
};