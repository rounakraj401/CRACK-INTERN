class Solution {
public:
    int passThePillow(int n, int time) {
        int x=time/(n-1);
        int rem=time%(n-1);

        if(x%2==1)
        {
            return n-rem;
        }
        return rem+1;
    }
};