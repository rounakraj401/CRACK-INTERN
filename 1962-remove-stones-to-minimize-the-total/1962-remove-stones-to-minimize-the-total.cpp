class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        int n=piles.size();
        
        long long int ans=0;
        for(int i=0;i<n;i++)
            pq.push(piles[i]);
        
        while(k--)
        {
            int maxm=pq.top();
            pq.pop();
            
            maxm-=maxm/2;
            pq.push(maxm);
        }
        
        while(!pq.empty())
        {
  //          cout<<pq.top()<<"\n";
            ans+=pq.top();
            pq.pop();
        }
        return (int)ans;
    }
};