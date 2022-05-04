class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int>m;
        int ans=0;
        for(int it:nums)
        {
            if(m[k-it]>0){
                ans++;
                m[k-it]--;
            }
            else
                m[it]++;
        }
        return ans;
    }
};