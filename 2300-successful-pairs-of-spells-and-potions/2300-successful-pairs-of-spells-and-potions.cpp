class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector< int>& p, long long succ) {
        long long int n=s.size();
        sort(p.begin(),p.end());
        
        vector<long long int>t(n);
        for(long long int i=0;i<n;i++)
        {
            if(succ%s[i]==0)t[i]=succ/s[i];
            else
                t[i]=(succ/s[i])+1;
        }
   //     for(int i=0;i<n;i++)cout<<s[i]<<"\n";
        
        vector<int>ans;
        for(long long int i=0;i<n;i++)
        {
            ans.push_back(p.size()-(lower_bound(p.begin(),p.end(),t[i])-p.begin()));
        }
        return ans;
    }
};