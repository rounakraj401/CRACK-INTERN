class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev=nums[0];
        int cur=1;
        
        int cnt=1;
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==prev && cnt<2)
            {
                cnt++;
                nums[cur++]=nums[i];
            }
            else if(nums[i]!=prev)
            {
                cnt=1;
                nums[cur++]=nums[i];
            }
            prev=nums[i];
        }
        return cur;
    }
};