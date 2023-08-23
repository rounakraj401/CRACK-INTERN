class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>>pq;
        unordered_map<char,int>mp;
        int n=s.length();
        
        for(auto it:s)
        {
            mp[it]++;
        }
        
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }
        string ans="";
        while(pq.size()>1)
        {
            auto it=pq.top();
            pq.pop();
            
            auto it1=pq.top();
            pq.pop();
            
            ans+=it.second;
            ans+=it1.second;
            
            it.first--;
            it1.first--;
            
            if(it.first>0)
                pq.push(it);
            if(it1.first>0)
                pq.push(it1);
        }
        if(!pq.empty()){
        if(pq.top().first>1)
            return "";
        else
            ans+=pq.top().second;
        }
        return ans;
    }
};