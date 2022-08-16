class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>setrow(n+1,0);
        vector<int>setcol(m+1,0);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    setrow[i]=1;
                    setcol[j]=1;
                }
            }
        }
        
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                if(setrow[row]==1 || setcol[col]==1)
                {
                    matrix[row][col]=0;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};