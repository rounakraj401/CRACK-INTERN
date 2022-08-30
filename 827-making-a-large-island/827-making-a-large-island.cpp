class Solution {
public:
    int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    
    bool isValid(vector<vector<int>> &grid, int &row, int &col, int id=1){
        int n=grid.size();
        if(id==1){
        if(row<0 || row>=n || col<0 || col>=n || grid[row][col]!=1){
            return false;
        }
        
        }
        else if(id==2){
            if(row<0 || row>=n || col<0 || col>=n || grid[row][col]<=1){
            return false;
        }
        }
        return true;
    }
    
    int dfs(vector<vector<int>> &grid, int row, int col,int &color){
        
        if(!isValid(grid,row,col)) return 0;
        
        grid[row][col]=color;
            
       
           
       return 1+dfs(grid, row+dir[0][0], col+dir[0][1],color)+
                dfs(grid, row+dir[1][0], col+dir[1][1],color)+
                dfs(grid, row+dir[2][0], col+dir[2][1],color)+
                dfs(grid, row+dir[3][0], col+dir[3][1],color);
        
        return 0;
    }
    int checkNeighbours(vector<vector<int>> &grid, unordered_map<int,int> &m, int n){
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
              
                if(grid[i][j]==0){
                    
                    unordered_set<int> se; // to check if we're not encountering the same id
                     int temp=0;
                    
                    for(int x=0;x<4;x++){ 
                        
                        int row=i+dir[x][0];
                        int col=j+dir[x][1];
                        
                     if(isValid(grid,row,col,2) && se.count(grid[row][col])==0){
                         
                         se.insert(grid[row][col]);
                         temp+=m[grid[row][col]]; 
                     }
                    }
                    temp+=1; 
                    ans=max(temp,ans);
                }
            }
        }
        return ans;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        
        int color =2; 
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                if(grid[i][j]==1){
                  mp[color]=dfs(grid,i,j,color); 
                  color++;
                }
            }
        }      
        
        ans=checkNeighbours(grid,mp,n);
        return ans==0?n*n:ans;
    }
};