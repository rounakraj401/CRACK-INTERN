class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int>pref(n,0);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                cnt++;
                pref[i]=1;
            }
            if(i>0)pref[i]+=pref[i-1];
        }
        if(cnt==0)return 0;
        int ans=1e8;
        for(int i=0;i<n;i++)
        {
            int j=i+cnt-1;
            int curr=0;
            if(j<n)
            {
                curr+=pref[j];
                if(i>0)curr-=pref[i-1];
            }
            else
            {
                curr+=pref[n-1];
                if(i>0)curr-=pref[i-1];
                j=j%n;
                curr+=pref[j];
            }
            ans=min(ans,cnt-curr);
        }
        return ans;
    }
};