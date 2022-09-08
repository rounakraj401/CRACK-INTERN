class Solution {
public:
    void uniquecombination(int idx,vector<int>&candidates,int target,vector<int>&temp,vector<vector<int>>&result)
    {
        if(idx==candidates.size())
        {
            if(target==0)
                result.push_back(temp);
            return;
        }
        
        if(candidates[idx]<=target)
        {
            temp.push_back(candidates[idx]);
            uniquecombination(idx,candidates,target-candidates[idx],temp,result);
            temp.pop_back();
        }
        uniquecombination(idx+1,candidates,target,temp,result);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>temp;
        
        uniquecombination(0,candidates,target,temp,result);
        return result;
    }
};