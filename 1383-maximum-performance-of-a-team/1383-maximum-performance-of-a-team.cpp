class Solution {
public:
    #define ll long long
    static bool cmp(pair<ll,ll>&a , pair<ll,ll>&b)
    {
        return a.second>b.second;
    }
    int maxPerformance(int n, vector<int>& speed, vector<int>& eff, int k) {
        vector<pair<ll,ll>>vec;
        for(int i=0;i<n;i++)
        {
            vec.push_back({speed[i],eff[i]});
        }
        sort(vec.begin(),vec.end(),cmp);
        
        priority_queue<ll,vector<ll>,greater<ll>>pq;
        
        ll cur_speed=0;
        ll ans=INT_MIN;
        
        ll cur_eff;
        
        for(int i=0;i<n;i++)
        {
            cur_eff=vec[i].second;
            cur_speed+=vec[i].first;
            
            ans=max(ans,cur_eff*cur_speed);
            
            pq.push(vec[i].first);
            if(pq.size()>k-1)
            {
                cur_speed-=pq.top();
                pq.pop();
            }
            
        }
        return (int)(ans%1000000007);
    }
};