class Solution {
public:
    string reverseWords(string str) {
        vector<string>temp;
        istringstream ss(str);
        string word;
        bool flag=false;
        
        while(ss>>word)
        {
            if(!flag)temp.push_back(word);
            else
                temp.push_back(word+" ");
            flag=true;
        }
        string ans="";
        for(int i=temp.size()-1;i>=0;i--)ans+=temp[i];
        return ans;
    }
};