class Solution {
public:
    bool ispal(string s,int l,int r)
    {
        while(l<=r)
        {
            if(s[l++]!=s[r--])return false;
        }
        return true;
    }
    void fun(string s,int idx,vector<vector<string>>&ans,vector<string>&path,map<pair<int,int>,bool>&m)
    {
        if(idx==s.length())
        {
            ans.push_back(path);
            return;
        }
        
        
        for(int i=idx;i<s.length();i++)
        {
            if(m[{idx,i}]==1 || ispal(s,idx,i))
            {
                m[{idx,i}]=1;
                path.push_back(s.substr(idx,i-idx+1));
                fun(s,i+1,ans,path,m);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>path;
        map<pair<int,int>,bool>m;
        fun(s,0,ans,path,m);
        return ans;
    }
};