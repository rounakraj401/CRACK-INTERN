class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=needle.length();
        if(n==0)return 0;
        
        return haystack.find(needle);
    }
};