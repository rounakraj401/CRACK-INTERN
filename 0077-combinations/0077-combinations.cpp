class Solution {
public:
    void fun(vector<vector<int>>&vec,vector<int>&temp,int i,int n,int k)
    {
        if(i>n+1)return;
        if(k==0)
        {
            vec.push_back(temp);
            return;
        }
        temp.push_back(i);
        fun(vec,temp,i+1,n,k-1);
        
        temp.pop_back();
        fun(vec,temp,i+1,n,k);
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>vec;
        vector<int>temp;
        
        fun(vec,temp,1,n,k);
        return vec;
    }
};