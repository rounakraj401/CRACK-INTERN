class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        set<string>st;
        for(auto it:dictionary)st.insert(it);
        vector<string>sen;
        string temp1="";
        for(int i=0;i<sentence.size();i++)
        {
            if(sentence[i]==' ')
            {
                sen.push_back(temp1);
                temp1.clear();
            }
            else
            {
                 temp1+=sentence[i];
            }
        }
        sen.push_back(temp1);

        string ans="";

        for(int i=0;i<sen.size();i++)
        {
            if(i!=0)ans+=" ";
 
            string temp="";
            bool flag=0;
            for(int j=0;j<sen[i].size();j++)
            {
                temp+=sen[i][j];
                if(st.count(temp))
                {
                    ans+=temp;
                    flag=1;
                    break;
                }
            }

            if(flag==0)ans+=temp;
        }

        return ans;
    }
};