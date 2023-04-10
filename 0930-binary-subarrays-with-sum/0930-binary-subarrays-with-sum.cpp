class Solution {
public:
    int numSubarraysWithSum(vector<int>& a, int goal) {
        int n=a.size();
        int ans=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        int pref=0;
        for(int i=0;i<n;i++)
        {
            pref+=a[i];
            if(mp.count(pref-goal))
                ans+=mp[pref-goal];
            
            mp[pref]++;
        }
        return ans;
    }
};