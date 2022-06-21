class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int>pq;
        int i=0;
        int diff=0;
        int n=heights.size();
        for(i=0;i<n-1;i++)
        {
 //           cout<<"Om\n";
            diff=heights[i+1]-heights[i];
            if(diff<=0)
                continue;
            
            bricks-=diff;
            pq.push(diff);
            
            if(bricks<0)
            {
                int x=pq.top();
                pq.pop();
                
                bricks+=x;
                ladders--;
            }
            if(ladders<0)
                break;
        }
        return i;
    }
};