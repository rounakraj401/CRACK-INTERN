class Solution {
public:
    int twoEggDrop(int n) {
        int z = (sqrt(8*n+1)-1)/2;
    if((z*(z+1))/2==n) return z;
    else return z+1;
    }
};