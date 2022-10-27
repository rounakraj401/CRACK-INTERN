class Solution {
public:
    int check_overlap(vector<vector<int>>&img1,vector<vector<int>>&img2,int n,int x,int y)
    {
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i+x>=0 && i+x<n && j+y>=0 && j+y<n && img1[i+x][j+y]==1 && img2[i][j]==1)
                    cnt++;
            }
        }
        return cnt;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ans=INT_MIN;
        int n=img1.size();
        for(int x=-n;x<n;x++)
        {
            for(int y=-n;y<n;y++)
            {
                ans=max(ans,check_overlap(img1,img2,n,x,y));
            }
        }
        return ans;
    }
};