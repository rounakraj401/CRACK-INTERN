class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        int f[100001]={0};
        int n=costs.size();
        for(int i=0;i<n;i++)
        {
            f[costs[i]]++;
        }
        
        int ans=0;
        int i=0;
        while(i<100001)
        {
            if(i>coins)break;
            
            if(f[i]!=0)
            {
                ans++;
                f[i]--;
                coins-=i;
                continue;
            }
            else
                i++;
        }
        return ans;
    }
};