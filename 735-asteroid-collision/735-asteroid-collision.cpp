class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int>st;
        int n=ast.size();
        vector<int>res;
        for(int i=0;i<n;i++)
        {
            if(res.empty() || ast[i]>0)
                res.push_back(ast[i]);
            else
             {
                while(!res.empty() && res.back()>0 && res.back()<abs(ast[i]))
                 res.pop_back();
                
                if(!res.empty() && res.back()+ast[i]==0)
                    res.pop_back();
                else if(res.empty() || res.back()<0)
                {
                    res.push_back(ast[i]);
                }
             }
        }
        return res;
    }
};