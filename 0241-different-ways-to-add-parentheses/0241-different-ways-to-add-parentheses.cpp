class Solution {
public:
    vector<int> diffWaysToCompute(string s) {
        vector<int>ans;
        vector<int>left;
        vector<int>right;

        int n=s.length();

        for(int i=0;i<n;i++)
        {
            if(s[i]=='+' || s[i]=='-' || s[i]=='*')
            {
                string leftt=s.substr(0,i);
                string rightt=s.substr(i+1);

                left=diffWaysToCompute(leftt);
                right=diffWaysToCompute(rightt);
            }

           for(auto it:left)
           {
            for(auto it1:right)
            {
                if(s[i]=='+')ans.push_back(it+it1);
                else if(s[i]=='-')ans.push_back(it-it1);
                else if(s[i]=='*')ans.push_back(it*it1);
            }
           }
        }
        if(!ans.size())ans.push_back(stoi(s));
        return ans;
    }
};