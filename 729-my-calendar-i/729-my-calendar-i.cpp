class MyCalendar {
public:
    vector<pair<int,int>>vec;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto it:vec)
        {
            if(!(end-1<it.first || start>it.second))return false;
        }
        vec.push_back({start,end-1});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */