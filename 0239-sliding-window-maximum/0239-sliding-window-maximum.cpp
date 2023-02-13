class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//     deque<int>dq;
//     int n=nums.size();
//     vector<int>ans;
//     for(int i=0;i<n;i++)
//     {
//       if(!dq.empty() && dq.front()==i-k)dq.pop_front();   // out of bound
            
//       while(!dq.empty() && nums[dq.back()]<=nums[i])dq.pop_back();// removing smaller elements than incoming element
//         dq.push_back(i);    // storing index of current max element
//         if(i>=k-1)ans.push_back(nums[dq.front()]);    //storing the max element for every k size array in ans vector.
//     }
        multiset<int>st;
        vector<int>ans;
        for(int i=0;i<k;i++)st.insert(nums[i]);
        ans.push_back(*st.rbegin());
        
        for(int i=k;i<nums.size();i++)
        {
            st.erase(st.find(nums[i-k]));
            st.insert(nums[i]);
            
            ans.push_back(*st.rbegin());
        }
        return ans;
    }
};