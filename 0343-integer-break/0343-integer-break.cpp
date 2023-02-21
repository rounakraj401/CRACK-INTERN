class Solution {
public:
    int integerBreak(int n) {
        int ans=1;
        if(n<4)return n-1;
        else if(n==4)return n;
        else{
         if(n%3==1)
         {
             int x=n/3;
             x--;
             
             while(x--)ans*=3;
             ans*=4;   
         }
         else if(n%3==2)
         {
             int x=n/3;
             while(x--)ans*=3;
             ans*=2;
         }
         else
         {
             int x=n/3;
             while(x--)ans*=3;
         }
                
      }
        return ans;
    }
};