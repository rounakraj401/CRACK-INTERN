class Solution {
public:
    int fun(int n)
    {
        int sum=0;
        while(n>0)
        {
            sum+=n%10;
            n/=10;
        }
        return sum;  
    }
    
    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        map<int,vector<int>>mp;
        
        for(int i=0;i<n;i++)
        {
            int sum=fun(nums[i]);
            mp[sum].push_back(nums[i]);
        }
        int maxm=-1;
        for(auto it:mp)
        {
            vector<int>v=it.second;
            if(v.size()>=2){
            sort(v.begin(),v.end());
            maxm=max(maxm,v[v.size()-1]+v[v.size()-2]);
            }
        }
        return maxm;
    }
};