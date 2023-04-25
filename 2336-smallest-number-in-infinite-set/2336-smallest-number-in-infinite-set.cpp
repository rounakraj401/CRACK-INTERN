class SmallestInfiniteSet {
public:
    priority_queue <int, vector<int>, greater<int> > pq;
    map<int,int>mp;
    SmallestInfiniteSet() {
        for(int i=1;i<10000;i++){
            pq.push(i);
            mp[i]=1;
        }
    }
    
    int popSmallest() {
        if(!pq.empty())
        {
            int x=pq.top();
            mp[x]=0;
            pq.pop();
            return x;
        }
        return NULL;
    }
    
    void addBack(int num) {
        if(mp[num]==0)
        {
            pq.push(num);
            mp[num]=1;
        }
        return;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */