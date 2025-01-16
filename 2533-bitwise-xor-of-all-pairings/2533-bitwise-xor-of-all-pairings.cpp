class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();

        int x1=0;
        for(auto it:nums1)x1^=it;
        int x2=0;
        for(auto it:nums2)x2^=it;

        if(n1%2==1 && n2%2==1)
        {
           return x1^x2;
        }
        else if(n1%2==1 && n2%2==0)return x2;
        else if(n1%2==0 && n2%2==1)return x1;
        return 0;
    }
};