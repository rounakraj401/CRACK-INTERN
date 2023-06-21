class Solution {
public:
    long long f(vector<int>&nums,vector<int>&cost,int med)
    {
        long long temp=0;
        for(int i=0;i<nums.size();i++)
         temp+=(1ll*abs(nums[i]-med))*(1ll*cost[i]);
        return temp;
    }
    long long minCost(vector<int>& A, vector<int>& cost) {
        long long l = 1, r = 1000000, res = f(A, cost, 1), x;
        while (l < r) {
            x = (l + r) / 2;
            long long y1 = f(A, cost, x);
            long long y2 = f(A, cost, x + 1);
            res = min(y1, y2);
            
            if (y1 < y2)
                r = x;
            else
                l = x + 1;
        }
        return res;
    }
};