class Solution {
public:
    int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
    
    int dfs(vector<vector<int>>& matrix,int n,int m,int i,int j,vector<vector<int>>& dp)
    {
        if(dp[i][j]!=-1)return dp[i][j];
                    
        int maxm=0;
        for(int it=0;it<4;it++)
        {
            int x=i+dir[it][0];
            int y=j+dir[it][1];
            
            if(x>=0 && y>=0 && x<n && y<m && matrix[x][y]>matrix[i][j]){
                int path=dfs(matrix,n,m,x,y,dp);
                maxm=max(maxm,path);
            }
        }
        return dp[i][j]=maxm+1;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()==1 || matrix.size()==0)return 0;
        
        int ans=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int path=dfs(matrix,n,m,i,j,dp);
                ans=max(path,ans);
            }
        }
        return ans;
    }
};