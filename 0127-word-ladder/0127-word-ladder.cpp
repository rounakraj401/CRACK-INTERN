class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>st;
        for(auto it:wordList)
        {
            st.insert(it);
        }
        
        if(!st.count(endWord))
            return 0;
        
        queue<pair<string , int>>pq;
        pq.push({beginWord,1});
        
        while(!pq.empty())
        {
            string s=pq.front().first;
            int len=pq.front().second;
            
            pq.pop();
            
            for(int i=0;i<s.length();i++)
            {
                char ss=s[i];
                for(char ch='a';ch<='z';ch++)
                {
                    s[i]=ch;
                    
                    if(s==endWord)
                        return len+1;
                    
                    if(st.find(s)!=st.end())
                    {
                        pq.push({s,len+1});
                        st.erase(s);
                    }
                    s[i]=ss;
                }
            }
        }
        return 0;
    }
};