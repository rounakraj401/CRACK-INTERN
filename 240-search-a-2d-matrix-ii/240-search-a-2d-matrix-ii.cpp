class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        int r=0;
        int c=m-1;
        
        while(r<n && c>=0)
        {
            int element=matrix[r][c];
            if(element==target)return 1;
            else if(element>target)
            {
                c--;
            }
            else
                r++;
        }
        return 0;
    }
};