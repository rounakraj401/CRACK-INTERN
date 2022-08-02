class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                pq.push(mat[i][j]);
            }
        }
        k--;
        while(k--)
            pq.pop();
        
        return pq.top();
    }
};