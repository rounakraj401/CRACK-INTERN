class Solution {
public:
    const int MOD=1e9+7;
    
    int maxArea(int h, int w, vector<int>& ho, vector<int>& ve) {
        int n1=ho.size();
        int n2=ve.size();
        
        sort(ho.begin(),ho.end());
        sort(ve.begin(),ve.end());
        
         int maxr=max(ho[0],h-ho[n1-1]);
         int maxc=max(ve[0],w-ve[n2-1]);
        
        for(int i=1;i<n1;i++)
        {
            maxr=max(maxr,ho[i]-ho[i-1]);
        }
        for(int i=1;i<n2;i++)
        {
            maxc=max(maxc,ve[i]-ve[i-1]);
        }
        
        int ans=(1LL*maxr*maxc)%MOD;
        return ans;
    }
};