class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>s;
        int res=0;
        int sum=0;
        int i=0;
        int j=0;
        while(j<n)
        {
            while(s.count(nums[j])>0)
            {
                s.erase(nums[i]);
                sum-=nums[i];
                i++;
            }
            sum+=nums[j];
            s.insert(nums[j++]);
            
            res=max(res,sum);
        }
        return res;
    }
};