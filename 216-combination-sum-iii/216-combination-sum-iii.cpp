class Solution {
public:
    void helper(int k,int n,int start,vector<int>&temp , vector<vector<int>>&ans)
    {
         if(n<0 && k<0)return ;
        
        if(k==0 && n==0)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=start;i<10;i++)
            {
                temp.push_back(i);
                helper(k-1,n-i,i+1,temp,ans);
                temp.pop_back();
            }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        vector<vector<int>>ans;
        
        helper(k,n,1,temp,ans);
        
        return ans;
    }
};