class Solution {
public:
    void dfs(vector<vector<int>>& graph , vector<int>&path ,vector<vector<int>>&ans , int curr,int target)
    {
       path.push_back(curr);
       if(curr==target)
       {
           ans.push_back(path);
       }
        
       for(int node:graph[curr])
       {
           dfs(graph,path,ans,node,target);
       }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>path;
        
        int n=graph.size();
        int curr=0;
        int target=n-1;
        
        dfs(graph,path,ans,curr,target);
        
        return ans;
    }
};