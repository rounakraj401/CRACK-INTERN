class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int val=floor(n/3);
        vector<int>ans;
        
        int cnt=0;
        int ele=nums[0];
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==ele)
            {
                cnt++;
            }
            else
            {
                if(cnt>val)ans.push_back(ele);
                ele=nums[i];
                cnt=1;
            }
        }
        if(cnt>val)ans.push_back(ele);
        return ans;
    }
};