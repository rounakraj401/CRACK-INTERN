class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& word) {
        unordered_set<string>st(word.begin(),word.end());
        queue<pair<string,int>>q;
        
        q.push({begin,1});
        while(!q.empty())
        {
            auto it=q.front();
            string s=it.first;
            int cnt=it.second;
            
            q.pop();
            if(s==end)return cnt;
            
            st.erase(s);
            
            for(int i=0;i<s.length();i++)
            {
                char ch=s[i];
                for(int j=0;j<26;j++)
                {
                    s[i]='a'+j;
                    
                    if(st.find(s)!=st.end())
                    {
                        q.push({s,cnt+1});
                    }
                }
                s[i]=ch;
            }
        }
        return 0;
    }
};