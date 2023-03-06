class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int>smaller;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            smaller.push_back(arr[i]-i-1);
        }
        if(k>smaller.back())
        {
            k-=smaller.back();
            return arr.back()+k;
        }
        if(smaller[0]>=k)
        {
            return k;
        }
        int idx=lower_bound(smaller.begin(),smaller.end(),k)-smaller.begin();
        
        return arr[idx-1]+(k-smaller[idx-1]);
    }
};