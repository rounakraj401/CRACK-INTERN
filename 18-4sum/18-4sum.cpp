class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>result;
        if(nums.empty())return result;
        
        
        long long int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
             {
                long long int sum=(nums[i]+nums[j]);
                long long int target2=target-sum;
                
                 int l=j+1;
                int h=n-1;
                
                while(l<h)
                {
                    if(nums[l]+nums[h]==target2)
                    {
                        vector<int>temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[h]);
                        
                        result.push_back(temp);
                        
                        while(l<h && nums[l]==temp[2])l++;
                        while(l<h && nums[h]==temp[3])h--;
                        
                    }
                    else if(nums[l]+nums[h]<target2)
                        l++;
                    else
                        h--;
                }
                while(j+1<n && nums[j+1]==nums[j])j++;
              }
            while(i+1<n && nums[i+1]==nums[i])i++;
        }
        
        return result;
    }
};