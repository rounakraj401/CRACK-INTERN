class Solution {
public:
    int ans=0;
    bool vis[16]={0};
    int countArrangement(int n,int p=1) {
        if(n<4)return n;
        if(p>n) return ans++;
        
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0 && (i%p==0 || p%i==0))
               {
                   vis[i]=1;
                   countArrangement(n,p+1);
                   vis[i]=0;
               }
        }
        return ans;
        
    }
};