class Solution {
public:
    int findparent(int u,vector<int>&parent){
        if(parent[u]==u){
            return u;
        }
        
        return parent[u] = findparent(parent[u], parent);
    }
    
    void unionfind(int u, int v, vector<int>&parent, vector<int>&rank){
        u = findparent(u, parent);
        v = findparent(v, parent);
        
        if(rank[u]>rank[v]){
            parent[v] = u;
        }
        
        else if(rank[v]>rank[u]){
            parent[u] = v;
        }
        
        else{
            parent[v] = u;
            rank[u]++;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        
        vector<int>rank(n,0);
        
        vector<int>parent(n);
        for(int i=0;i<n;i++)parent[i]=i;
        
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])
                  unionfind(i,j,parent,rank);
            }
        }
        
        unordered_set<int>st;
        for(int i=0;i<n;i++)
        {
            st.insert(findparent(i,parent));
        }
        return n-st.size();
    }
};