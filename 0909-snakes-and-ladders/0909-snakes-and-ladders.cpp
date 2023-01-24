class Solution {
public:
    
    vector<int>find(int val,int n)
    {
        int row=n-1 - (val-1)/n;
        int col=(val-1)%n;
        
        if(row%2==n%2)
        {
            return {row,n-1-col};
        }
        else
            return {row,col};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<vector<bool>>vis(n,vector<bool>(n,0));
        
        queue<int>pq;
        pq.push(1);
        vis[n-1][0]=1;
        
        int ans=0;
        
        while(!pq.empty())
        {
            int size=pq.size();
            
            while(size--)
            {
                int currval=pq.front();
                pq.pop();
                
                if(currval==n*n)
                    return ans;
                
                for(int dice=1;dice<=6;dice++)
                {
                    if(currval+dice>n*n)
                        break;
                    
                    vector<int>pos=find(currval+dice,n);
                    int r=pos[0];
                    int c=pos[1];
                    
                    if(vis[r][c]==0)
                    {
                        vis[r][c]=1;
                        
                        if(board[r][c]==-1)
                            pq.push(currval+dice);
                        else
                            pq.push(board[r][c]);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};