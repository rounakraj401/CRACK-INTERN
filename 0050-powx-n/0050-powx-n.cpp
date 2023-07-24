class Solution {
public:
    double myPow(double x, int n) {
       
        double res=1;
        while(n)
        {
            if(n%2)
            {
                if(n>=0)res*=x;
                else
                    res/=x;
            }
            n/=2;
            x*=x;
        }
        return res;
    }
};