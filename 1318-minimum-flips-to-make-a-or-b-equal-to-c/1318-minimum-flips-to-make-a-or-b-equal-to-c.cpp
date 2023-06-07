class Solution {
public:
    int minFlips(int a, int b, int c) {
         int cnt=0;
        for(int i=0;i<32;i++)
        {
            int b1=a&(1<<i)?1:0;
            int b2=b&(1<<i)?1:0;
            int b3=c&(1<<i)?1:0;
            
            if(b1+b2==0 && b3!=0)
                cnt++;
            else if(b3==0)
                cnt+=(b1+b2);
 //           cout<<cnt<<"\n";
        }
        return cnt;
    }
};