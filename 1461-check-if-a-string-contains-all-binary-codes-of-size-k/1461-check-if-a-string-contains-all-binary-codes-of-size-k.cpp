class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (k > s.size()) return false;
        
        unordered_set<string>ans;
        
        for (int i = 0; i <= s.size()-k; i++)
            ans.insert(s.substr(i, k));
        
        return ans.size() == pow(2, k);
    }
};