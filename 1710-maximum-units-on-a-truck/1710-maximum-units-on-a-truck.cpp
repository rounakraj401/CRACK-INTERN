class Solution {
public:
    
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& box, int size) {
        int ans=0;
        int n=box.size();
        int i=0;
        sort(box.begin(),box.end(),cmp);
        
        while(size>0 && i<n)
        {
            int x=min(size,box[i][0]);
            size-=x;
            
            ans+=x*box[i][1];
    //        cout<<ans<<"\n";
            i++;
        }
        return ans;
        
    }
};