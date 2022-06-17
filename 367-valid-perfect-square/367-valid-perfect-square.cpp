class Solution {
public:
    bool isPerfectSquare(int num) {
        return ceil(sqrt(num)==floor(sqrt(num)));
    }
};