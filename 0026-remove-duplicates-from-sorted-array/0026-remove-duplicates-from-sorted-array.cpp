class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int prev=nums[0];
        
        int cur=1;
        for(int i=1;i<n;i++)
        {
            if(prev!=nums[i])
            {
                nums[cur++]=nums[i];
            }
            prev=nums[i];
        }
        return cur;
    }
};