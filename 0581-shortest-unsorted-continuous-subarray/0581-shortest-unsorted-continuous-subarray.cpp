class Solution {
public:
    int findUnsortedSubarray(vector<int>& a) {
        int n=a.size();
        vector<int>b(a);
        sort(b.begin(),b.end());
        
        int i=0;
        int j=n-1;
        while(i<n && a[i]==b[i])
            i++;
        while(j>i && a[j]==b[j])
            j--;
        
        return j-i+1;
        
    }
};