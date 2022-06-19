class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        next_permutation(s.begin(),s.end());
        long long x=stoll(s);
        
        if(x>INT_MAX || n>=x)return -1;
        return x;
    }
};