class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        int n=pre.size();
        vector<int>adj[num];
         vector<int>deg(num,0);
        for(int i=0;i<n;i++)
        {
            adj[pre[i][0]].push_back(pre[i][1]);
            deg[pre[i][1]]++;
        }
        
        queue<int>q;
        
        for(int i=0;i<num;i++)
        {
            if(deg[i]==0)q.push(i);
        }
        int cnt=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            cnt++;
            for(auto it:adj[node])
            {
                deg[it]--;
                if(deg[it]==0)q.push(it);
            }
        }
        if(cnt==num)
        {
            return true;
        }
        return false;
    }
};