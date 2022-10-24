class Solution {
public:
    int fun(int idx,int len,vector<bool>vec,vector<string>&arr)
    {
        if(idx==arr.size())
            return len;
        
        int x=arr[idx].length();
        
        int op1=fun(idx+1,len,vec,arr);    //nottake
        int op2=0;
        bool flag=0;
        for(int i=0;i<x;i++)
        {
            if(vec[arr[idx][i]-'a'])
            {
                flag=1;
                break;
            }
        }
        //take
        if(flag==0)
        {
         bool flag2=0;
         for(int i=0;i<x;i++)
         {
            if(vec[arr[idx][i]-'a'])flag2=1;
             vec[arr[idx][i]-'a']=1;
         }
         if(flag2==0)op2=fun(idx+1,len+x,vec,arr);
        }
        
        return max(op1,op2);
    }
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        vector<bool>vec(26,0);
        return fun(0,0,vec,arr);
    }
};