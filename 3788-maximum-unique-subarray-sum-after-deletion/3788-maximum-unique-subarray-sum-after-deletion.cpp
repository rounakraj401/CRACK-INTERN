class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n=nums.size();
        int maxm=*max_element(nums.begin(),nums.end());

        if(maxm<0)return maxm;
        int sum=0;
        set<int>st;
        for(auto it:nums)
        {
            if(it>0 && st.count(it)==0){
                sum+=it;
                st.insert(it);
            }
        }
        return sum;
    }
};