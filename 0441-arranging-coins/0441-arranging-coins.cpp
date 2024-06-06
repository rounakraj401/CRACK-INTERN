class Solution {
public:
    int arrangeCoins(int n) {
        long long int x1=1;
        long long int x2=n;
        long long int ans;
        while(x1<=x2)
        {
          long long int mid=(x1+x2)/2;
          if(mid*(mid+1)/2<=n)
          {
            ans=mid;
            x1=mid+1;
          }
          else
           x2=mid-1;
        }
        return ans;
    }
};