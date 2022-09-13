class Solution {
public:
    
    void generate(int lp,int rp,string s , vector<string>&ans)
    {
        if(lp==0 && rp==0){
            ans.push_back(s);
            return;
        }
                
        if(lp>0)
        {
          generate(lp-1,rp,s+"(",ans);
        }
        if(lp<rp)
        {
          generate(lp,rp-1,s+")",ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s="";
        generate(n,n,s,ans);
        
        return ans;
    }
};