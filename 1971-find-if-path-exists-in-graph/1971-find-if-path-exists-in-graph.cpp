class Solution {
public:
    vector<int>parent;
    int findpar(int u)
{
    if(u==parent[u])return u;
    return parent[u]=findpar(parent[u]);
}
void unionn(int a,int b)
{
        int x=findpar(a);
        int y=findpar(b);
        if(x==y)
            return;
        parent[y]=x;
}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
       parent.resize(n);
        for(int i=0;i<n;i++)parent[i]=i;
        
        for(int i=0;i<edges.size();i++)
        {
            unionn(edges[i][0],edges[i][1]);
        }
 
        return (findpar(source)==findpar(destination));
    }
};