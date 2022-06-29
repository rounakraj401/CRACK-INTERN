class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b)
    {
        if(a[0]==b[0])return a[1]<b[1];
        
        return a[0]>b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>>ans;
        
        sort(people.begin(),people.end(),cmp);
        
        for(int i=0;i<people.size();i++)
        {
            int idx=people[i][1];
            ans.insert(ans.begin()+idx,people[i]);
        }
        return ans;
    }
};