class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        
        int key[n];int mst[n];
        for(int i=0;i<n;i++)
        { 
            key[i]=INT_MAX;
            mst[i]=0;
        }
        
        key[0]=0;
        for(int i=0;i<n-1;i++)
        {
            int minm=INT_MAX;
            int u;
            
            for(int j=0;j<n;j++)
            {
                if(mst[j]==0 && key[j]<minm)
                {
                    minm=key[j];
                    u=j;
                }
            }
            mst[u]=1;
            
            for(int j=0;j<n;j++)
            {
                if(mst[j]==0)key[j]=min(key[j],abs(points[j][1]-points[u][1])+abs(points[j][0]-points[u][0]));
            }
            // for(int j=0;j<n;j++)cout<<key[j]<<" ";
            // cout<<"\n";
        }
        
        int ans=0;
        for(int i=0;i<n;i++)ans+=key[i];
        
        return ans;
    }
};