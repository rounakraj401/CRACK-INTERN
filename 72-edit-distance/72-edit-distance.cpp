class Solution {
public:
    int solve(string w1,string w2,int i,int j,vector<vector<int>>&dp)
    {
        if(i<0)return j+1;
        if(j<0)return i+1;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        if(w1[i]==w2[j])
            return dp[i][j]=solve(w1,w2,i-1,j-1,dp);
        else{
        int x=1+solve(w1,w2,i,j-1,dp);  // insert
        int y=1+solve(w1,w2,i-1,j,dp);  // delete
        int z=1+solve(w1,w2,i-1,j-1,dp);   // replace
        
        return dp[i][j]=min(x,min(y,z));
        }
    }
    int minDistance(string w1, string w2) {
        int n=w1.size();
        int m=w2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(w1,w2,n-1,m-1,dp);
        
    }
};