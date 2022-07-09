class Solution {
public:
    void fun(int idx,string s,vector<string>&ans,string &st,unordered_set<string>&ss)
    {
        if(idx>=s.length())
        {
            ans.push_back(st);
                return;
        }
        string temp="";
        for(int i=idx;i<s.length();i++)
        {
            temp+=s[i];
            if(ss.find(temp)!=ss.end())
            {
                if(idx>0)st+=' ';
                st+=temp;
                fun(i+1,s,ans,st,ss);
                
                while(st.size() && st.back()!=' ')st.pop_back();
                if(st.size()>0)st.pop_back();
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& word) {
        vector<string>ans;
        string st;
        unordered_set<string>ss(word.begin(),word.end());
        fun(0,s,ans,st,ss);
        return ans;
    }
};