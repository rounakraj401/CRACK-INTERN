class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>> >pq;
        long long int ans=0;
        
        int n=costs.size();
        
        int l=0;
        int r=n-1;
        
        for(l=0;l<candidates;l++)
        {
            pq.push({costs[l],l,0});
        }
        for(int i=0;i<candidates;i++)
        {
            if(l<=r){
                pq.push({costs[r],r,1});
                r--;
            }
        }
        
        while(k--)
        {
            auto it = pq.top();
            pq.pop();
            
            if(it[2]==0)
            {
                if(l<=r)
                {
                    pq.push({costs[l],l,0});
                    l++;
                }
            }
            else
            {
                if(l<=r)
                {
                    pq.push({costs[r],r,1});
                        r--;
                }
            }
            
            ans+=it[0];
        }
        return ans;
    }
};