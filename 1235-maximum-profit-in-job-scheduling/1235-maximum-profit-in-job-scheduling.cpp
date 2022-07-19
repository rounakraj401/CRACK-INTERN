class Solution {
public:
    int jobScheduling(vector<int>& start, vector<int>& end, vector<int>& profit) {
        vector<pair<pair<int,int>,int>>vec;
        int n=profit.size();
        for(int i=0;i<n;i++)
        {
            vec.push_back({{end[i],start[i]},profit[i]});
        }
        sort(vec.begin(),vec.end());
        
        vector<int>dp(n+1);
        dp[1]=vec[0].second;
        
        for(int i=1;i<n;i++)
        {
            int j=i-1;
            while(j>=0 && vec[j].first.first>vec[i].first.second)
                j--;
            
            dp[i+1]=max(dp[i], j!=-1? vec[i].second+dp[j+1]:vec[i].second);
        }
        
        return dp[n];
    }
};