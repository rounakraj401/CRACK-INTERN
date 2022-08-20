class Solution {
public:

    int minRefuelStops(int target, int startFuel, vector<vector<int>>& station) {
        int n=station.size();
        priority_queue<int,vector<int>>pq;
        int i=0;
        int ans=0;
        
        while(startFuel<target)
        {
            ans++;
            while(i<station.size() && station[i][0]<=startFuel)
            {
                pq.push(station[i++][1]);
            }
            
            if(pq.empty())return -1;
            
            startFuel+=pq.top();
            pq.pop();
        }
        return ans;
    }
};