class Solution {
public:
    
    int findpar(int n,vector<int>&parent)
    {
        if(parent[n]==n)return n;
        return parent[n]=findpar(parent[n],parent);
    }
    void unionn(int a,int b,vector<int>&parent,int &cnt)
    {
        a=findpar(a,parent);
        b=findpar(b,parent);
        
        if(a!=b)
        {
            parent[b]=a;
            cnt--;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int cnt=n;
        
        vector<int>parent(n+1);
        for(int i=0;i<n+1;i++)parent[i]=i;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j && isConnected[i][j]==1)
                    unionn(i+1,j+1,parent,cnt);
            }
        }
        return cnt;
    }
};