class Solution {
public:
    static bool cmp(pair<int,string>&a  , pair<int,string>&b)
    {
        if(a.first==b.first)
            return a.second<b.second;
        
        return a.first>b.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>mp;
        vector<pair<int,string>>vec;
        
        for(int i=0;i<words.size();i++)
        {
            mp[words[i]]++;
        }
        
        for(auto it:mp)
        {
            vec.push_back({it.second,it.first});
        }
        sort(vec.begin(),vec.end(),cmp);
        vector<string>ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(vec[i].second);
        }
        return ans;
    }
};