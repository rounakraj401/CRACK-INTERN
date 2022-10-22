class Solution {
public:
    string minWindow(string s, string t) {
        
         int n=s.length();
         int m=t.length();
        
        if(m==0 || n==0 || n<m)return "";
        
        vector<int>vec(256,0);
        for(auto it:t)
            vec[it]++;
        
        int start=0;
        int end=0;
        int cnt=0;
        int ans_start=0;
        int min_len=INT_MAX;
        
        while(end<n)
        {
            if(vec[s[end]]>0)
                cnt++;
            
            vec[s[end]]--;
            
            while(cnt==m)
            {
                if(min_len>end-start+1)
                {
                    min_len=end-start+1;
                    ans_start=start;
                }
                
                vec[s[start]]++;
                if(vec[s[start]]>0)cnt--;
                
                start++;
            }
            
            end++;
        }
        if(min_len==INT_MAX)return "";
        return s.substr(ans_start,min_len);
    }
};