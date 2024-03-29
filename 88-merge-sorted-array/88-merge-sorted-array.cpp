class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        for(int k=nums1.size()-1;k>=0;k--)
        {
            if(i>=0 && j>=0 && nums1[i]>=nums2[j])
                nums1[k]=nums1[i--];
            else if(j>=0)
                nums1[k]=nums2[j--];
        }
        
        return ;
    }
};