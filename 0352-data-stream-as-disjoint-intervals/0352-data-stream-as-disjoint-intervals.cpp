class SummaryRanges {
public:
    set<int>st;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>ans;
        int i;
        
        set<int>st1=st;
        
        while(!st1.empty())
        {
            i=*st1.begin();
            vector<int>temp;
            while(!st1.empty() && st1.find(i)!=st1.end())
            {
                temp.push_back(i);
                st1.erase(st1.find(i));
                i++;
            }
            if(temp.size()==1)
             ans.push_back({temp[0],temp[0]});
            else
             ans.push_back({temp[0],temp[temp.size()-1]});   
        }
        
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */