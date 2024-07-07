class Solution {
public:
    int numWaterBottles(int num1, int num2) {
        int ans=num1;
        
        while(num1>=num2)
        {
            int d=num1%num2;
            num1=num1/num2;
            ans+=num1;
            num1+=d;
        }
        return ans;
    }
};