class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());

        if(nums[n-1]<=0)return nums[n-1];

        int sum=0;
        set<int>st;

        for(int i=n-1;i>=0;i--)
        {
            if(st.count(nums[i]))
            {
                continue;
            }
            if(nums[i]>0)
            {
                sum+=nums[i];
                st.insert(nums[i]);
            }
            else
             break;
        }
        return sum;
    }
};