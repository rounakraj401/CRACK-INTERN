class Solution {
public:
    bool check(string s,int i,int j)
    {
        while(i<=j){
        if(s[i]!=s[j])return false;
            
          i++;
          j--;
        }
        return true;
    }
//     int fun(string s,int i,int j,vector<vector<int>>&dp)
//     {
//         if(i>j)return 0;
//         if(i==j)return 1;
        
//         if(dp[i][j]!=-1)return dp[i][j];
        
//         if(check(s,i,j))return dp[i][j]=1+fun(s,i+1,j,dp)+fun(s,i,j-1,dp)-fun(s,i+1,j-1,dp);
        
//         return dp[i][j]=fun(s,i+1,j,dp)+fun(s,i,j-1,dp)-fun(s,i+1,j-1,dp);
//     }
    int countSubstrings(string s) {
       int sum=0;
       for(int i=0;i<s.size();i++)
       {  
           string ans="";
           for(int j=i;j<s.size();j++)
           {
               ans+=s[j];
               if(check(ans,0,ans.size()-1))
                   sum++;
           }
       }
        return sum;    
    }
};