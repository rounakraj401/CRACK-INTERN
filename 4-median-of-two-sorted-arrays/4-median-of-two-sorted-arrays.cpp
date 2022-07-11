class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        
        vector<int>res;
        int i=0;int j=0;
        int k=0;
        
        while(i<n && j<m)
        {
            if(nums1[i]<=nums2[j])
            {
                res.push_back(nums1[i]);
                i++;
            }
            else
            {
                res.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n)res.push_back(nums1[i++]);
        while(j<m)res.push_back(nums2[j++]);
        
        if((n+m)%2)return (double)res[(n+m)/2];
        else
            return (double)(res[(n+m)/2]+res[(n+m)/2-1])/2;
    }
};