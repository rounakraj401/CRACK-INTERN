class Solution {
public:
    bool check(string temp)
    {
        set<char>st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');

        if(st.count(temp[0]) && st.count(temp[temp.size()-1]))
         return 1;

        return 0;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int>pref(n,0);

        for(int i=0;i<n;i++)
        {
            if(check(words[i]))pref[i]=1;
        }
        for(int i=1;i<n;i++)pref[i]+=pref[i-1];

        int m=queries.size();
        vector<int>ans;
        for(int i=0;i<m;i++)
        {
           int lb=queries[i][0];
           if(lb==0)
            ans.push_back(pref[queries[i][1]]);
           else
            ans.push_back(pref[queries[i][1]] - pref[queries[i][0] -1]);
        }
        return ans;
    }
};