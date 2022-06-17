class Solution {
public:
    int numRabbits(vector<int>& ans) {
        unordered_map<int,int>mp;
        int n=ans.size();

        int res=0;
        for(int i=0;i<n;i++)
        {
            mp[ans[i]]++;
        }
        for(auto it:mp)
        {
            if(it.first==0)res+=it.second;
            else
            {
                int grps=it.first+1;
                int freq=it.second;
                
                if(freq%grps==0)freq/=grps;
                else
                    freq=(freq/grps)+1;
                
                res+=grps*freq;
            }
        }
        return res;
    }
};