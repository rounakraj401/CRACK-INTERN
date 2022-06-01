class Solution {
public:
    vector<int> runningSum(vector<int>& p) {
        
        for(int i=1;i<p.size();i++)
            p[i]+=p[i-1];
        
        return p;
    }
};