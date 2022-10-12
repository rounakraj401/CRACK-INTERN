class Solution {
public:
    int largestPerimeter(vector<int>& a) {
        sort(a.begin(),a.end());
        int n=a.size();
        int ans=0;
        for(int i=n-1;i>=2;i--)
        {
            if(a[i]<a[i-1]+a[i-2])
                return a[i]+a[i-1]+a[i-2];
        }
        return ans;
    }
};