class Solution {
public:
    bool iszero(vector<vector<int>>&mat)
    {
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j])
                    return false;
            }
        }
        return true;
    }
    
    int recur(vector<vector<int>>&mat,vector<vector<int>>&vis,int n,int m)
    {
        if(iszero(mat))
            return 0;
        
        int ans=100000;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {   
                if(!vis[i][j])
                {
                    vis[i][j]=1;
                    int b,c,d,e,f;
                    
                    b=mat[i][j];
                    mat[i][j]^=1;
                    
                    if(i-1>=0)
                    {
                        c=mat[i-1][j];
                        mat[i-1][j]^=1;
                    }
                    if(i+1<n)
                    {
                        d=mat[i+1][j];
                        mat[i+1][j]^=1;
                    }
                    if(j-1>=0)
                    {
                        e=mat[i][j-1];
                        mat[i][j-1]^=1;
                    }
                    if(j+1<m)
                    {
                        f=mat[i][j+1];
                        mat[i][j+1]^=1;
                    }
                    ans=min(ans,1+recur(mat,vis,n,m));
                    
                    // backtarcking
                    
                    mat[i][j]=b;
                    if(i-1>=0)mat[i-1][j]=c;
                    if(i+1<n)mat[i+1][j]=d;
                    if(j-1>=0)mat[i][j-1]=e;
                    if(j+1<m)mat[i][j+1]=f;
                    
                    vis[i][j]=0;
                    
                }
            }
        }
        return ans;
    }
    int minFlips(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<int>>vis(n+1,vector<int>(m+1,0));
        int ans=recur(mat,vis,n,m);
        
        if(ans==100000)
            return -1;
        return ans;
    }
};