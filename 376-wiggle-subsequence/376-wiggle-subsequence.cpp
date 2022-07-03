class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()==1)return 1;
        
        int prev=nums[1]-nums[0];
        int ans=(prev!=0)?2:1;
        
        for(int i=2;i<nums.size();i++)
        {
            int cur=nums[i]-nums[i-1];
            
            if(cur>0 && prev<=0  || cur<0 && prev>=0)
            {
                ans++;
                prev=cur;
            }
        }
        return ans;
    }
};