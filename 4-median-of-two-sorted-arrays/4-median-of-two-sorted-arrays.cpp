class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

//         BRUTE FORCE   
//         int n=nums1.size();
//         int m=nums2.size();
        
//         vector<int>res;
//         int i=0;int j=0;
//         int k=0;
        
//         while(i<n && j<m)
//         {
//             if(nums1[i]<=nums2[j])
//             {
//                 res.push_back(nums1[i]);
//                 i++;
//             }
//             else
//             {
//                 res.push_back(nums2[j]);
//                 j++;
//             }
//         }
//         while(i<n)res.push_back(nums1[i++]);
//         while(j<m)res.push_back(nums2[j++]);
        
//         if((n+m)%2)return (double)res[(n+m)/2];
//         else
//             return (double)(res[(n+m)/2]+res[(n+m)/2-1])/2;
//     }
        
        
//     BINARY SEARCH
        
        if(nums2.size()<nums1.size())return findMedianSortedArrays(nums2,nums1);
        
        int n=nums1.size();
        int m=nums2.size();
        
        int l=0;
        int h=n;
        
        while(l<=h)
        {
            int mid=(l+h)>>1;
            int cut1=mid;
            int cut2=(n+m+1)/2-mid;
            
            int l1= cut1==0?INT_MIN:nums1[cut1-1];
            int l2= cut2==0?INT_MIN:nums2[cut2-1];
            
            int r1= cut1==n?INT_MAX:nums1[cut1];
            int r2= cut2==m?INT_MAX:nums2[cut2];
            
            if(l1<=r2 && l2<=r1)
            {
                if((n+m)%2==0)
                    return (max(l1,l2)+min(r1,r2))/2.0;
                else
                    return max(l1,l2);
            }
            else if(l1>r2)
            {
                h=mid-1;
            }
            else
                l=mid+1;
        }
        return 0.0;
    }
};