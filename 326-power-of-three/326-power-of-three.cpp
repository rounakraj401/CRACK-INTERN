class Solution {
public:
    bool isPowerOfThree(int n) {
        return n>0?(1162261467 / n == 1162261467 / (double)n):0;
    }
};