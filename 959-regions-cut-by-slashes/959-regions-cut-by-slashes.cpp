class Solution {
public:
    int find(int node,vector<int>&par)
    {
        if(par[node]==node)return node;
        return par[node]=find(par[node],par);
    }
    void unionn(int a,int b,int &cnt,vector<int>&rank,vector<int>&par)
    {
        a=find(a,par);
        b=find(b,par);
        
        if(a!=b)
        {
            if(rank[a]>rank[b])par[b]=a;
            else if(rank[b]>rank[a])par[a]=b;
            else{
                par[b]=a;
                rank[a]++;
            }
        }
        else
            cnt++;
    }
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        int dot=n+1;
        int cnt=1;
        
        vector<int>par(dot*dot);
        vector<int>rank(dot*dot);
        
        for(int i=0;i<dot*dot;i++)par[i]=i;
        for(int i=0;i<dot*dot;i++)rank[i]=1;
        
        for(int i=0;i<dot;i++)
        {
            for(int j=0;j<dot;j++)
            {
                if(i==0 || j==0 || i==dot-1 || j==dot-1)
                {
                    int cellno=(i*dot)+j;
                    if(cellno!=0)unionn(0,cellno,cnt,rank,par);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='/')
                {
                    int cell1=(i*dot)+(j+1);
                    int cell2=((i+1)*dot)+j;
                     unionn(cell1,cell2,cnt,rank,par);
                    
                }
                else if(grid[i][j]=='\\')
                {
                    int cell1=(i*dot)+j;
                    int cell2=((i+1)*dot)+(j+1);
                    unionn(cell1,cell2,cnt,rank,par);   
                }
           }
        }
        return cnt;
        
}
};