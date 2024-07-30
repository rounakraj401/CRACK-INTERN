class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        
        vector<int>vec1(n,0),vec2(n,0);
        vec1[0]=s[0]=='b';
        vec2[0]=count(s.begin(), s.end(), 'a');
        for(int i=1; i<n; i++){
            vec1[i]=vec1[i-1]+(s[i]=='b');
            vec2[i]=vec2[i-1]-(s[i-1]=='a');
        }
        
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            ans=min(ans,vec1[i]+vec2[i]-1);
        }
        return ans;
    }
};