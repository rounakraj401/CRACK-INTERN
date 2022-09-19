class Solution {
public:
    static bool cmp(pair<pair<int,int>,double>&a , pair<pair<int,int>,double>&b )
    {
        return a.second<b.second;
    }
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<pair<int,int>,double>>vec;
        
        int n=arr.size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                double x=arr[i]/(double)arr[j];
                vec.push_back({{arr[i],arr[j]} , x});
            }
        }
        
        sort(vec.begin(),vec.end(),cmp);
        
        vector<int>ans;
        ans.push_back(vec[k-1].first.first);
        ans.push_back(vec[k-1].first.second);
        
        return ans;
    }
};