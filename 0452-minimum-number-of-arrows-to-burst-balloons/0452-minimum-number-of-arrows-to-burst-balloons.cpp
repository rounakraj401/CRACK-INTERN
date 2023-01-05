class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans=1;
        sort(points.begin(),points.end());
        
        int range=points[0][1];
        
        for(auto it:points)
        {
            if(it[0]>range)
            {
                ans++;
                range=it[1];
            }
            range=min(range,it[1]);
        }
        return ans;
    }
};