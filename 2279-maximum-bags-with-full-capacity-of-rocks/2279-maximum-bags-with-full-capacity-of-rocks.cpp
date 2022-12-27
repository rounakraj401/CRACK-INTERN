class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
         int n=capacity.size();
        vector<int>remaining(n);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            remaining[i]=capacity[i]-rocks[i];
            if(remaining[i]==0)ans++;
        }
        sort(remaining.begin(),remaining.end());
        
        int i=ans;
        
        while(i<n && remaining[i]<=additionalRocks)
        {
            ans++;
            additionalRocks-=remaining[i];
            i++;
        }
        return ans;
    }
};