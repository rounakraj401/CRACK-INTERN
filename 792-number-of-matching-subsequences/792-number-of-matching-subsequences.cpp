class Solution {
public:
    bool isSubsequence(string s1, string s2, int m, int n){
        int j = 0;
        for(int i = 0; i < m && j < n; i++){
            if(s1[i] == s2[j]) j++;
        }
        return j == n;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        map<string,int> mp;
        
        for(auto x:words)mp[x]=-1;
        
        for(auto x: words){
		
            if(mp[x]!=-1) {
                if(mp[x] ==1){
                    count++;
                }
                continue;
            }
			
            mp[x] = isSubsequence(s, x, s.size(), x.size());
            count += (mp[x] == 1);
        }
        return count;
    }
};