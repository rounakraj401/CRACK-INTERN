class UndergroundSystem {
public:
    map< pair<string,string> , vector<int>>checkout;
    map<int,pair<string,int>>checkin;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkin[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        
        auto it=checkin[id];
        string in=it.first;
        int in_time=it.second;
        
        checkout[{in,stationName}].push_back(t-in_time);
    }
    
    double getAverageTime(string startStation, string endStation) {
        vector<int>vec=checkout[{startStation,endStation}];
        double ans=0;
        for(auto it:vec)
            ans+=it;
        
        return ans/vec.size();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */