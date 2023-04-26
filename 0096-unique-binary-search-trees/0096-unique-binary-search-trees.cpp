class Solution {
public:   
    int numTrees(int n) {
        vector<int>dp(20,0);
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
        
        if(n<4)
            return dp[n];
        
        for(int i=4;i<=n;i++)
        {
            int temp=0;
            for(int j=1;j<=i;j++)
            {
                temp+=(dp[j-1]*dp[i-j]);
            }
            dp[i]=temp;
        }
        return dp[n];
    }
};