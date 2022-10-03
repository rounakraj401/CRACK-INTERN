class Solution {
public:
    int minCost(string s, vector<int>& time) {
        int n=s.size();
        int ans=0;
        
        for(auto i=0;i<n;)
        {
            int maxm=0;
            int sum=0;
            char ch=s[i];
            
            for(;i<n && ch==s[i];i++)
            {
                sum+=time[i];
                maxm=max(maxm,time[i]);
            }
            ans+=sum-maxm;
        }
        return ans;
    }
};