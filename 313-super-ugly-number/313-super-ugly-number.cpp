class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int x=primes.size();
        vector<long long int>res;
        vector<int>cnt(x,0);
        
        res.push_back(1LL);
        
        priority_queue<pair<long long int,int>,vector<pair<long long int,int>>,greater<pair<long long int,int>>>pq;
        for(int i=0;i<x;i++)
        {
            pq.push({primes[i],i});
        }
        
        while(res.size()<n)
        {
            auto[value,id]=pq.top();
            pq.pop();
            
            if(value!=res.back())
                res.push_back(value);
            
            cnt[id]++;
            
            pq.push({res[cnt[id]]*primes[id] , id});
        }
        return res[n-1];
    }
};