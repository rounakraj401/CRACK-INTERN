class Solution {
public:
    bool isPerfectSquare(int x){if (x >= 0) {int sr = sqrt(x);return (sr * sr == x);}return false;}

    bool judgeSquareSum(int c) {
        int x=sqrt(c);
        if(c<3)return true;
        
        for(int i=1;i<=x;i++)
        {
            if(isPerfectSquare(c-(i*i)))
                return true;
        }
        return false;
    }
};