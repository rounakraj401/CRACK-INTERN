class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1 || num==4)return true;
        
        int l=1;
        int h=num;
        
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(pow(mid,2)==num)
                return true;
            else if(pow(mid,2)>num)
            {
                h=mid-1;
            }
            else
                l=mid+1;
        }
        return false;
    }
};