class Solution {
public:
    int find_par(int n,vector<int>&parent)
    {
        if(parent[n]==n)return n;
        return parent[n]=find_par(parent[n],parent);
    }
    
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        vector<int>parent(n);
        unordered_map<int,int>maxx;
        vector<int>count(n,1);
        
        for(int i=0;i<n;i++)
        {
            maxx[i]=vals[i];
            parent[i]=i;
        }
        
        int ans=n;
        
        sort(edges.begin(),edges.end(),[&](vector<int>&a,vector<int>&b)
        {
            int m=max(vals[a[0]] ,vals[a[1]]);
            int n=max(vals[b[0]], vals[b[1]]);
            
            return m<n;
        });
        
        for(auto it:edges)
        {
            int a=find_par(it[0],parent);
            int b=find_par(it[1],parent);
            
            if(maxx[a]!=maxx[b])
            {
                if(maxx[a]>maxx[b])
                {
                    parent[b]=a;
                }
                else
                {
                    parent[a]=b;
                }
            }
            else
            {
                parent[b]=a;
                ans+=(count[a])*count[b];
                count[a]+=count[b];
            }
        }
        return ans;
    }
};