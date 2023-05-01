class Solution {
public:
    double average(vector<int>& salary) {
        double ans=0;
        int n=salary.size();
        for(auto it:salary)
            ans+=it;
        
        ans-=*max_element(salary.begin(),salary.end());
        ans-=*min_element(salary.begin(),salary.end());
        
        return ans/(n-2);
    }
};