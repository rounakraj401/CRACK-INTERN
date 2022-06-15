class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n-2;i++)
        {
            if(i==0 || (i>0 && nums[i]!=nums[i-1]))
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
                    
                    while(it1<it2 && nums[it1]==nums[it1+1])it1++;
                    while(it1<it2 && nums[it2]==nums[it2-1])it2--;  
                    
                    it1++;
                    it2--;
                }
            }
           }
        }
        return ans;
        
    }
};