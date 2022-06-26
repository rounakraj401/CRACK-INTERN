class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n=arr.size();
        int sum=0;
        for(int i:arr)sum+=i;
        
        if(k==n)
        { 
            return sum;
        }
        vector<int>pref(n,0);
        pref[0]=arr[0];
        for(int i=1;i<n;i++)pref[i]=arr[i]+pref[i-1];
        
        int minm=pref[n-k-1];
        for(int i=1;i<=k;i++)
        {
 //           cout<<pref[i+n-k-1]<<" "<<pref[i-1]<<"\n";
            minm=min(minm,pref[i+n-k-1]-pref[i-1]);
        }
        return sum-minm;
    }
};