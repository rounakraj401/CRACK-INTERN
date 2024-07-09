class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double sum=(double)customers[0][0];
        double ans=0;
        int n=customers.size();

        for(auto it:customers)
        {
            int arr=it[0];
            int t=it[1];

            if(sum>arr)
            {
             sum+=t;
             ans+=(sum-arr);
            }
            else{
             sum=arr+t;
             ans+=t;
            }
        }
        return ans/(double)n;
    }
};