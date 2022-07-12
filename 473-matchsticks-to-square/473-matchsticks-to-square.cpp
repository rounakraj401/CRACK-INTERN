class Solution {
public:
    bool fun(vector<int>&stick,int target,vector<int>&vec,int idx)
    {
        if(idx==stick.size())
        {
            if(vec[0]==vec[1] && vec[1]==vec[2] && vec[2]==vec[3])return true;
            return false;
        }
        
        for(int i=0;i<4;i++)
        {
            if(vec[i]+stick[idx]>target)continue;
            
            int j=i-1;
            while(j>=0)
            {
                if(vec[j]==vec[i])
                    break;
                j--;
            }
            if(j!=-1)continue;
            
            vec[i]+=stick[idx];
            if(fun(stick,target,vec,idx+1))
                return true;
            
            vec[i]-=stick[idx];
        }
        return false;
    }
    bool makesquare(vector<int>&stick) {
        int sum=accumulate(stick.begin(),stick.end(),0ll);
        if(sum%4!=0)return false;
        
        int target=sum/4;
        sort(stick.begin(),stick.end(),greater<int>());
        vector<int>vec(4,0);
        
        return fun(stick,target,vec,0);
    }
};