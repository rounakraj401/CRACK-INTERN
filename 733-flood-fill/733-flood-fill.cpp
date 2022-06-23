class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& image,int color,int x)
    {
        if(i<0 || i>=image.size() || j<0 || j>=image[0].size() || image[i][j]!=x || image[i][j]==color)
            return;
        
        image[i][j]=color;
        dfs(i+1,j,image,color,x);
        dfs(i-1,j,image,color,x);
        dfs(i,j+1,image,color,x);
        dfs(i,j-1,image,color,x);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int x=image[sr][sc];
        dfs(sr,sc,image,color,x);
        return image;
    }
};