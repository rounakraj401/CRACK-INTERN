class Solution {
public:
    void fun(int i,vector<vector<int>>&ans,vector<int>&ds,vector<int>& cand, int target)
    {
        if(i==cand.size())
        {
            if(target==0)
                ans.push_back(ds);
            
            return ;
        }
        
        
        if(cand[i]<=target)
        {
            ds.push_back(cand[i]);
            fun(i,ans,ds,cand,target-cand[i]);
            ds.pop_back();
        }
        fun(i+1,ans,ds,cand,target);
        
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        fun(0,ans,ds,cand,target);
        
        return ans;
    }
};