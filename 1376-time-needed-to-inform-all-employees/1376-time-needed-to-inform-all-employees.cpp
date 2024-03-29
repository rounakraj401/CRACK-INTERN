class Solution {
public:
    int dfs(int i, vector<int>m[], vector<int>& informTime, int mx = 0) {
    for (auto d : m[i])
        mx = max(mx, dfs(d, m, informTime));
    return informTime[i] + mx;
}
int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    vector<int>m[n+1];
    for(auto i = 0; i < manager.size(); ++i)
        if (manager[i] != -1)
            m[manager[i]].push_back(i);
    return dfs(headID, m, informTime);
}
};