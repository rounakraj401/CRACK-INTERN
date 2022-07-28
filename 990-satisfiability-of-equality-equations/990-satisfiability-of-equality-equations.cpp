class Solution {
    private:vector<int> parent, rank;
    
public:
    int findPar(int node) {
		if (parent[node] == node) {
			return node;
		}
		return parent[node] = findPar(parent[node]);
	}
    
	void unionSize(int u, int v)
    {
        u=findPar(u);
        v=findPar(v);
        if(rank[u]<rank[v])
        {
            parent[u]=v;
        }
        else if(rank[u]>rank[v])
            parent[v]=u;
        else 
        {
            parent[v]=u;
            rank[u]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        int n=26;
        for (int i = 0; i <= n; i++) {
			parent.push_back(i);
			rank.push_back(1);		
		}
        
        for(auto i :equations){
            if(i[1] != '!'){
               unionSize(int(i[0])- 'a', int(i[3])- 'a'); 
            }
        }
        
        for(auto i :equations)
        {
            if(i[1] == '!')
            {
                if(findPar(int(i[0])-'a')==findPar(int(i[3])-'a'))return false;
            }  
        }
        return true;
    }
};