class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=0;
        int min_ele=prices[0];
        
        for(int i=1;i<prices.size();i++)
        {
            min_ele=min(min_ele,prices[i]);
            ans=max(ans,prices[i]-min_ele);
        }
        return ans;
    }
};