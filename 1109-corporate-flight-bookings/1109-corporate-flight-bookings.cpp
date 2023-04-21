class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        unordered_map<int,int>mp;
        for(auto it:bookings)
        {
            mp[it[0]]+=it[2];
            mp[it[1]+1]-=it[2];
        }
        vector<int>ans;
        int pref=mp[1];
        ans.push_back(pref);
        
        for(int i=2;i<=n;i++)
        {
            pref+=mp[i];
            ans.push_back(pref);
        }
        return ans;
    }
};