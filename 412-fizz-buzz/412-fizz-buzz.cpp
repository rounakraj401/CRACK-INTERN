class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n);
        
        for(int i = 1; i <= n; i++){
            // divisible by 3 and 5, 3*5 == 15
            if(i % 15 == 0)
                res[i-1] = "FizzBuzz";
            else if(i % 3 == 0)
                res[i-1] = "Fizz";
            else if(i % 5 == 0)
                res[i-1] = "Buzz";
            // to_string is convert i to string, because res is string array
            else
                res[i-1] = to_string(i);
        }
        
        return res;
    }
};