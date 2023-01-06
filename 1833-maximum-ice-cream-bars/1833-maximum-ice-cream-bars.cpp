class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int ans=0;
        
        int idx=0;
        while(coins>0 && idx<costs.size())
        {
            if(costs[idx]<=coins)ans++;
            coins-=costs[idx++];
        }
        return ans;
    }
};