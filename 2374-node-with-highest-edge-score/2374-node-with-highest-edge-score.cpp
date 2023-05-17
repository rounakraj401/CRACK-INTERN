class Solution {
public:
    int edgeScore(vector<int>& edges) {
        unordered_map<int,long long int>mp;
        for(int i=0;i<edges.size();i++)
        {
            mp[edges[i]]+=i;
        }
        long long int ans=INT_MAX,maxm=INT_MIN;
        for(auto it:mp)
        {
            if(it.second>maxm)
            {
                maxm=it.second;
                ans=it.first;
            }
            else if(it.second==maxm && it.first<ans)
            {
                ans=it.first;
            }
        }
      
        return (int)ans;
    }
};