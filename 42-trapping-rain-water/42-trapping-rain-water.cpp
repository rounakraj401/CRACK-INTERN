class Solution {
public:
    int trap(vector<int>& a) {
        int ans=0;
        int n=a.size();
        vector<int>pre_for(n);
        vector<int>pre_back(n);
        
        pre_for[0]=a[0];
        pre_back[n-1]=a[n-1];
        
        for(int i=1;i<n;i++)
        {
            pre_for[i]=max(a[i],pre_for[i-1]);
        }
        for(int i=n-2;i>=0;i--)
        {
            pre_back[i]=max(a[i],pre_back[i+1]);
        }
        
        for(int i=0;i<n;i++)
        {
            ans+=min(pre_for[i],pre_back[i])-a[i];
        }
        return ans;
    }
};