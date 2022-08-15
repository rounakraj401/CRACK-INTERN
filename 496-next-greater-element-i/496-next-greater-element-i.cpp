class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        int n=nums2.size();
        
        vector<int>next_greater(n);
        
        unordered_map<int,int>mp;
        
        for(int i=0;i<n;i++)mp[nums2[i]]=i;
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=nums2[i])
                st.pop();
            
            next_greater[i]=st.empty()?-1:st.top();
            st.push(nums2[i]);
        }
        
//        for(int i=0;i<n;i++)cout<<next_greater[i]<<" ";
        
        vector<int>ans;
        for(int i=0;i<nums1.size();i++)
        {        
            ans.push_back(next_greater[mp[nums1[i]]]);
        }
        return ans;
    }
};