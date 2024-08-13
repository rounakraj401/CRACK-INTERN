class Solution {
public:
    void fun(int i,int target, vector<vector<int>>&ans, vector<int>&ds ,vector<int>&cand)
    {
            if(target==0)
            {
                ans.push_back(ds);
                return;
            }
        
       for(int j=i;j<cand.size();j++)
       {
           if(j>i && cand[j]==cand[j-1])continue;
           if(cand[j]>target)break;
           ds.push_back(cand[j]);
           fun(j+1,target-cand[j],ans,ds,cand);
           ds.pop_back();
       }
    }
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        sort(cand.begin(),cand.end());
        vector<vector<int>>ans;
        vector<int>ds;
        fun(0,target,ans,ds,cand);
        return ans;
    }
};