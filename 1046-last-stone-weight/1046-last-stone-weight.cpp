class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto it:stones)
        {
            pq.push(it);
        }
        while(pq.size()>1)
        {
            int s1=pq.top();
            pq.pop();
            
            int s2=pq.top();
            pq.pop();
            
            if(s1==s2)continue;
            else
            {
                pq.push(max(s1,s2) - min(s1,s2));
            }
        }
        if(pq.size()==0)return 0;
        return pq.top();
    }
};