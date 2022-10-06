class Solution {
public:
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}};
    
    int swimInWater(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int low = 0, high = n*n-1;
        while(low < high){
            int mid = low + (high - low)/2;
            vector<vector<int>> vis(n, vector<int>(n,0));
            if(isReachable(mid,n, 0, 0, vis,grid)){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
    
    bool isReachable(int T,int N,int i,int j,vector<vector<int>>&vis , vector<vector<int>>&grid)
    {
        
        if(i == N-1 && j == N-1){
            return true;
        }
        
        vis[i][j] = true;
        for(auto dir : dirs){
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            if(new_i >= 0 && new_i < N && new_j >= 0 && new_j < N && !vis[new_i][new_j] && grid[i][j]<=T && grid[new_i][new_j] <= T){
                
                if(isReachable(T, N,new_i, new_j, vis , grid)){
                    return true;
                }
                
            }
        }
        
        return false;
    }
};