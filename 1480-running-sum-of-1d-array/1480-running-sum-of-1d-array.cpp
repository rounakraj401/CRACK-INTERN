class Solution {
public:
    vector<int> runningSum(vector<int>& p) {
        int n=p.size();
        for(int i=1;i<n;i++)
            p[i]+=p[i-1];
        
        return p;
    }
};