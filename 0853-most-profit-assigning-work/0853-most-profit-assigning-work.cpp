class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=profit.size();
        int m=worker.size();

        vector<pair<int,int>>vec(n);
        sort(worker.begin(),worker.end());
        
        for(int i=0;i<n;i++)
        {
            vec[i].first=difficulty[i];
            vec[i].second=profit[i];
        }
        sort(vec.begin(),vec.end());
        int maxm=0;
        int temp=0;

        int ans=0;
        for(int i=0,j=0;i<m;i++)
        {
            while(j<n && vec[j].first<=worker[i])
            {
                temp=max(temp,vec[j].second);
                j++;
            }

            if(j>0 && vec[j-1].first<=worker[i])
            {
                maxm=maxm+temp;
            }
        }
        return maxm;
    }
};