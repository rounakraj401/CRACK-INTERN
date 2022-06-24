class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int>pq;
        long long int sum=0;
        for(auto it:target)
        {
            sum+=it;
            pq.push(it);
        }
        
        while(pq.top()!=1)
        {
            sum-=pq.top();
            if(sum==0 || sum>=pq.top())return false;
            int old=pq.top()%sum;
            
            if(sum!=1 && old==0)return false;
            pq.pop();
            pq.push(old);
            sum+=old;

        }
        return true;
    }
};