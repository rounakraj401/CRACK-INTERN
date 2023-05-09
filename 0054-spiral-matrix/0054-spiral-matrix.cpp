class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<int>ans;
        int count=0;
        int total=row*col;
        
        int rs=0;
        int re=row-1;
        
        int cs=0;
        int ce=col-1;
        while(count<total)
        {
            for(int i=cs;i<=ce && count<total;i++)
            {
                ans.push_back(matrix[rs][i]);
                count++;
            }
            rs++;
            
             for(int i=rs;i<=re && count<total;i++)
            {
                ans.push_back(matrix[i][ce]);
                count++;
            }
            ce--;
             for(int i=ce;i>=cs && count<total;i--)
            {
                ans.push_back(matrix[re][i]);
                count++;
            }
            re--;
            
             for(int i=re;i>=rs && count<total;i--)
            {
                ans.push_back(matrix[i][cs]);
                count++;
            }
            cs++;
            
        }
        return ans;
    }
};