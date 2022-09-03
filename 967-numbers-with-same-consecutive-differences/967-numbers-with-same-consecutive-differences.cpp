class Solution {
public:
    void checkNos(int nums,int len,int n,int k,vector<int>&ans)
    {
        if(len==n)
        {
            ans.push_back(nums);
            return;
        }
        
        int last_digit=nums%10;
        
        if(k==0)
        {
            checkNos(nums*10+last_digit , len+1,n,k,ans);
        }
        else
        {
          if(last_digit+k<=9)
            checkNos(nums*10+last_digit+k , len+1, n,k,ans);
            
          if(last_digit-k>=0)
            checkNos(nums*10+last_digit-k , len+1, n,k,ans);
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans;
        for(int i=1;i<10;i++)
        {
            checkNos(i,1,n,k,ans);
        }
        return ans;
    }
};