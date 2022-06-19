class Solution {
public:
//    static bool lexo(string s1,string s2)
// {
//     int n=min(s1.length(),s2.length());
//     for(int i=0;i<n;i++)
//     {
//         if(s1[i]!=s2[i])
//         {
//             if(s1[i]<s2[i])return false;
//             else
//             return true;
//         }
//     }
//     if(s1.size()>s2.size())return true;
//     else
//         return false;

// }
    vector<vector<string>> suggestedProducts(vector<string>& p, string Word) {
//        sort(p.begin(),p.end(),lexo);
        
//         vector<vector<string>>ans;
//         string s="";
            
//         for(int i=0;i<Word.length();i++)
//         {
//             vector<string>temp;
//             s+=Word[i];
//             int j=0;
//             for(int k=p.size()-1;k>=0 && j<3;k--)
//             {
//                 if(s==p[k].substr(0,i+1)){
//                     temp.push_back(p[k]);
//                     j++;
//                 }
//             }
//             ans.push_back(temp);
//         }
//     return ans;
        
        
        sort(p.begin(),p.end());
        int l=0,r=p.size()-1;
        vector<vector<string>> ans;
        for(int i=0;i<Word.size();i++)
        {
            char ch=Word[i];
            vector<string> temp;
            while(l<=r && p[l][i]!=ch)
                l++;
            while(l<=r && p[r][i]!=ch)
                r--;
            for(int j=l;j<l+min(3,r-l+1);j++)
                temp.push_back(p[j]);
            ans.push_back(temp);
        }
        return ans;
        }
};