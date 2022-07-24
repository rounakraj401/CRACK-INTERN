class Solution {
public:
    void dfs(int i,vector<int>&idx,vector<char>&ch, string&s ,vector<bool>&vis,vector<vector<int>>&graph)
    {
        vis[i]=1;
        idx.push_back(i);
        ch.push_back(s[i]);
        
        for(auto it:graph[i])
        {
            if(vis[it]==0)
                dfs(it,idx,ch,s,vis,graph);
        }
        
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        vector<bool>vis(n,0);
        vector<vector<int>>graph(n);
        
        for(int i=0;i<pairs.size();i++){
            graph[pairs[i][0]].push_back(pairs[i][1]);
            graph[pairs[i][1]].push_back(pairs[i][0]);
        }
        
        for(int i=0;i<n;i++)
        {
            vector<int>idx;
            vector<char>ch;
            
            if(vis[i]==0)
            {
                dfs(i,idx,ch,s,vis,graph);
            }
            sort(idx.begin(),idx.end());
            sort(ch.begin(),ch.end());
            
            for(int j=0;j<idx.size();j++)
            {
                s[idx[j]]=ch[j];
            }
        }
        return s;
    }
};