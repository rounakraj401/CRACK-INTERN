class Solution {
public:
    bool isSubSeq(string s1, string s2){
        int m=s1.size();
        int n=s2.size();
        
        int j = 0;
        for(int i = 0; i < m && j < n; i++){
            if(s1[i] == s2[j]) j++;
        }
        return j == n;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
    int n=words.size();
    int ans=0;
        
    map<string,int> m;
	for(int i = 0; i < n; i++){
		m[words[i]]++;
	}
	for(auto it : m){
		if(isSubSeq(s,it.first)) ans += it.second;
	}
	return ans; 
    }
};