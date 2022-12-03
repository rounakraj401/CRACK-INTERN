class Solution {
public:
    bool static cmp(const pair<char,int>&a ,const pair<char,int>&b){
        return a.second>b.second;}
    
    string frequencySort(string s) {
        int n=s.length();
        map<char,int>m;
        for(int i=0;i<n;i++)
            m[s[i]]++;
        
        vector<pair<int,int>>vec;
        for(auto it:m)
        {
            vec.push_back({it.first,it.second});
        }
        sort(vec.begin(),vec.end(),cmp);
        string ans="";
        for(int i=0;i<vec.size();i++)
        {
            for(int j=0;j<vec[i].second;j++)
                ans+=vec[i].first;
        }
        return ans;
    }
};