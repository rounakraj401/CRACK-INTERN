class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int total_cost=0,total_fuel=0;
        
        for(int i=0;i<n;i++)
        {
            total_fuel+=gas[i];
            total_cost+=cost[i];
        }
        
        if(total_cost>total_fuel)
            return -1;
        
        int start=0;
        int curr_fuel=0;
        
        for(int i=0;i<n;i++)
        {
           if(curr_fuel<0)
           {
               start=i;
               curr_fuel=0;
           }
            curr_fuel+=(gas[i]-cost[i]);
        }
        return start;
    }
};