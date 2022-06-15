class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        int x=n-k+1;
        
        priority_queue<int>pq;
        for(int i=0;i<x;i++)
            pq.push(nums[i]);
        
        for(int i=x;i<n;i++)
        {
            if(nums[i]<pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};