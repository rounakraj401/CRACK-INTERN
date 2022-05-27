class Solution {
public:
    int numberOfSteps(int num) {
        if(num==0)return 0;
            else
                return log2(num)+__builtin_popcount(num);
        
    }
};