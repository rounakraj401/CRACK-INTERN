// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    void dfs(vector<int>adj[], vector<int>&vis,int i)
    {
        vis[i]=1;
        for(auto it:adj[i])
        {
            if(!vis[it])
            dfs(adj,vis,it);
        }
    }
	int findMotherVertex(int n, vector<int>adj[])
	{
	    vector<int>vis(n,0);
	    
	    int last=0;
	    for(int i=0;i<n;i++)
	    {
	        if(!vis[i])
	        {
	            dfs(adj,vis,i);
	            last=i;
	        }
	    }
	    
	    for(int i=0;i<n;i++)vis[i]=0;
	    
	    dfs(adj,vis,last);
	    
	    for(int i=0;i<n;i++)
	    {
	        if(!vis[i])
	        return -1;
	    }
	    return last;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends