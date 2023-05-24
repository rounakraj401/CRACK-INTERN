class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long int n=nums1.size();
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++)
        {
            vec.push_back({nums2[i],nums1[i]});
        }
        sort(vec.rbegin(),vec.rend());
        priority_queue<int,vector<int>,greater<int>>pq;
        
        long long int sum=0,ans=0;
        for(int i=0;i<k-1;i++)
        {
            sum+=vec[i].second;
            pq.push(vec[i].second);
        }
        
        for(int i=k-1;i<n;i++)
        {
            sum+=vec[i].second;
            pq.push(vec[i].second);
            
            ans=max(ans,sum*vec[i].first);
            
            sum-=pq.top();
            pq.pop();
        }
        return ans;
    }
};