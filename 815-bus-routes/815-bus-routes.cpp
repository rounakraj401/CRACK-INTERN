class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int src, int tar) {
        if(src==tar)return 0;
        
        map<int,vector<int>>m;
        int n=routes.size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<routes[i].size();j++)
            {
                m[routes[i][j]].push_back(i);
            }
        }
        
        unordered_set<int>st;
        int ans=1;
        queue<int>q;
        
        for(auto it:m[src])
        {
                q.push(it);
               st.insert(it);
        }
        
        while(!q.empty())
        {
            int x=q.size();
             while(x--){
                 
             int node=q.front();
             q.pop();
        
            for(auto it:routes[node])
            {
                if(it==tar)return ans;

                for(auto j:m[it])
                {
                    if(st.find(j)==st.end())
                    {
                        q.push(j);
                        st.insert(j);
                    }
                }
            }  
            }
            ans++;
        }
        return -1;
    }
};