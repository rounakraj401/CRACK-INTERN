class Solution {

public:
    const int mod=1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        map<int,long long int>mp;
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<arr.size();i++)mp[arr[i]]=1;
        
        for(int i=0;i<arr.size();i++)
        {
            for(int j=2;j<sqrt(arr[i]);j++)
            {
                if(arr[i]%j==0 && (j*(arr[i]/j))==arr[i])
                {
                    if(mp.find(j)!=mp.end() && mp.find(arr[i]/j)!=mp.end())
                    {
                        mp[arr[i]]+=(((mp[j]%mod) * (mp[arr[i]/j]%mod))%mod*2)%mod;
                    }
                }
            }
            
            if(int(sqrt(arr[i])) * int(sqrt(arr[i]))==arr[i]  && mp.find(sqrt(arr[i]))!=mp.end())
            {
                mp[arr[i]]+=(((mp[sqrt(arr[i])]%mod)*(mp[sqrt(arr[i])])%mod)%mod);
            }
        }
        
        long long int ans=0;
        for(auto it:mp)
            ans+=it.second;
        
        return ans%mod;
    }
};