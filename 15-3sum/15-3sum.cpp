class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n-2;i++)
        {
             int it1=i+1;
             int it2=n-1;
            
             int x=-nums[i];
                
             while(it1<it2)
             {
                if(nums[it1]+nums[it2]<x)
                {
                    it1++;
                }
                else if(nums[it1]+nums[it2]>x)
                {
                    it2--;
                }
                else if(nums[it1]+nums[it2]==x)
                {
                    vector<int>temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[it1]);
                    temp.push_back(nums[it2]);
                    
                    ans.push_back(temp);
                    
                    while(it1<it2 && temp[1]==nums[it1])it1++;
                    while(it1<it2 && temp[2]==nums[it2])it2--;  
                    
                }
            }
            while(i+1<n && nums[i+1]==nums[i])i++;
        }
        return ans;
        
    }
};