class Solution {
    private:vector<int> parent, size;
    
public:
    int findPar(int node) {
		if (parent[node] == node) {
			return node;
		}
		return parent[node] = findPar(parent[node]);
	}
	void unionSize(int u, int v) {
		int pu = findPar(u);
		int pv = findPar(v);
		if (pu == pv) {
			return;
		}
		if (size[pu] < size[pv]) {
			parent[pu] = pv;
			size[pv] += size[pu];
		}
		else {
			parent[pv] = pu;
			size[pu] += size[pv];
		}
    }
    bool equationsPossible(vector<string>& equations) {
        int n=26;
        for (int i = 0; i <= n; i++) {
			parent.push_back(i);
			size.push_back(1);		
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