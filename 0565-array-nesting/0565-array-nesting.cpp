class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n=nums.size();
        vector<int>vis(n,0);

        int cnt=0;
        int ans=0;

        for(int i=0;i<n;i++)
        {
            int idx=i;
            cnt=0;

            while(!vis[idx])
            {
                vis[idx]=1;
                idx=nums[idx];
                cnt++;
            }
            ans=max(ans,cnt);
        }

        return ans;
    }
};