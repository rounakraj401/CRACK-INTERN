class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& group) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<group.size();i++)
        {
            mp[group[i]].push_back(i);
        }
        
        vector<vector<int>>ans;
        for(auto it:mp)
        {
            int x=it.second.size()/it.first;
            
            for(int i=0;i<x;i++){
                
             vector<int>temp;
                for(int j=it.first*i ; j<it.first+(it.first*i) ; j++)temp.push_back(it.second[j]);
             ans.push_back(temp);
                
            }
        }
        return ans;
    }
};