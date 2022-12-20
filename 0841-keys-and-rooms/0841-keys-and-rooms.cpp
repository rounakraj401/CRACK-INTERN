class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        
        vector<bool>vis(n,0);
        vis[0]=1;
        queue<int>pq;
        
        pq.push(0);
        while(!pq.empty())
        {
            int n=pq.size();
            
            int it=pq.front();
            pq.pop();
            
            for(int i=0;i<rooms[it].size();i++)
                if(!vis[rooms[it][i]])
                {
                    pq.push(rooms[it][i]);
                    vis[rooms[it][i]]=1;
                }
        }
                        
        for(int i=0;i<n;i++)
        {
          if(vis[i]==0)return false;                    
        }
        return true;
                
    }
};