class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int max_reachable=0;
        int last_reached=0;
        int i=0;
        
        while(last_reached<n-1)
        {
            max_reachable=max(max_reachable,i+nums[i]);
            if(i==last_reached)
            {
                last_reached=max_reachable;
                ans++;
            }
            i++;
        }
        return ans;
    }
};