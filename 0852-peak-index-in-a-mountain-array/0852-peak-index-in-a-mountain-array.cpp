class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int l=0;
        int h=n-1;
        while(l<h)
        {
            int mid=l+(h-l)/2;
            
            if(arr[mid]>arr[mid+1])
            {
                h=mid;
            }
            else
                l=mid+1;
        }
        return l;
        // return end-->both start and end will point to same no at the end
    }
};