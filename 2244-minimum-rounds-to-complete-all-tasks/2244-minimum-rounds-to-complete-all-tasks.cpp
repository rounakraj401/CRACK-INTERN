class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int>m;
        int n=tasks.size();
        for(int i=0;i<n;i++)
            m[tasks[i]]++;
        
        for(auto it:m)
        {
            if(it.second==1)return -1;
        }
        int ans=0;
        for(auto it:m)
        {
            if(it.second%3==0)ans+=it.second/3;
            else
                ans+=it.second/3+1;
        }
        return ans;
    }
};