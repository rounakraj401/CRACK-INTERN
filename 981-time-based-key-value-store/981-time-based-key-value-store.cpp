class TimeMap {
public:
    
    // static bool cmp(pair<pair<string,string>,int>&a , pair<pair<string,string>,int>&b)
    // {
    //     return a.second<b.second;
    // }
    unordered_map<string,map<int,string>>mp;
    
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mp[key].insert({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto it=mp[key].upper_bound(timestamp);
        if(it==mp[key].begin())
            return "";
        
        it--;
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */