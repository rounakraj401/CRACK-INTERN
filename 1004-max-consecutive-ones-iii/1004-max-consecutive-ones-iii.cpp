class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;
        
        int i=0;
        int j=0;
        int ans=INT_MIN;
        
        while(i<n)
        {
            if(nums[i]==0)cnt++;
            while(cnt>k)
            {
                if(nums[j]==0)
                    cnt--;
                j++;
            }
            ans=max(ans,i-j+1);
            i++;
        }
        return ans;
    }
};