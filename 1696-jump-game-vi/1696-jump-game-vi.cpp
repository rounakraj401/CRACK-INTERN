class Solution {
public:
//     int fun(int idx,vector<int>&nums,int k,vector<int>&dp)
//     {
//         if(idx==0)return nums[0];
        
//         if(dp[idx]!=-1)return dp[idx];
        
//         int maxi=INT_MIN;
//         for(int i=1;i<=k;i++)
//         {
//             if(idx-i>=0){
//               maxi=max(maxi,nums[idx]+fun(idx-i,nums,k,dp));
//             }
//         }
//         return dp[idx]=maxi;
//     }
    int maxResult(vector<int>& nums, int k) {
        // int n=nums.size();
        // vector<int>dp(n+1,-1);
        // return fun(n-1,nums,k,dp);
        
        vector<int> v(nums.size());
        v[0] = nums[0];
        priority_queue<pair<int, int>> pq;
        pq.push({nums[0], 0});
        for (int i = 1; i < nums.size(); i++)
        {
      //      cout<<pq.top().first<<" "<<pq.top().second<<"\n";
            
            while (!pq.empty() && pq.top().second < i - k)
                pq.pop();
            v[i] = nums[i] + pq.top().first;
            pq.push({v[i], i});
        }
        return v[nums.size() - 1];
    }
};