class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        if(n==1)return 0;
        
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]].push_back(i);
        }
        int step=0;
        
        vector<bool>vis(n+1,0);
        queue<int>pq;
                
        pq.push(0);
        vis[0]=1;
        
        while(!pq.empty())
        {
            int size=pq.size();
            while(size--)
            {
                int pos=pq.front();
                pq.pop();
                
                if(pos==n-1)return step;
                
                vector<int>&jumpNextIndices = mp[arr[pos]];
                jumpNextIndices.push_back(pos+1);
                jumpNextIndices.push_back(pos-1);
                
                for(auto it:jumpNextIndices)
                {
                    if(it>=0 && it<n && !vis[it])
                    {
                        vis[it]=1;
                        pq.push(it);
                    }
                }
                
                jumpNextIndices.clear();
            }
            step++;
        }
        return -1;
    }
};