class Solution {
public:
    int fun(vector<int>&job , vector<vector<int>>&dp , int d,int idx)
    {
        if(d==1)
        {
            int maxm=0;
            for(int i=idx;i<job.size();i++)
                maxm=max(maxm,job[i]);
            
            return maxm;
        }
        
       if(dp[d][idx]!=-1)return dp[d][idx];
        
        int ans=INT_MAX;
        int left_max=0;
        
        for(int i=idx;i<job.size()-d+1;i++)
        {
            left_max=max(left_max,job[i]);
            int right_max=fun(job,dp,d-1,i+1);
            
            ans=min(ans,left_max+right_max);
        }
        
        return dp[d][idx]=ans;
    }
    int minDifficulty(vector<int>& job, int d) {
        if(job.size()<d)return -1;
        
        vector<vector<int>>dp(d+1,vector<int>(job.size(),-1));
                              
        return fun(job,dp,d,0);
    }
};