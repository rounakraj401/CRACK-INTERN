class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
        int ans=INT_MIN;
        
        int cnt=0;
        while(j<n)
        {
           if(nums[j]==0)cnt++;
            
            while(i<n && cnt==2)
            {
                if(nums[i]==0)cnt--;
                i++;
            }
            ans=max(ans,j-i);
            j++;
        }
        return ans;
    }
};