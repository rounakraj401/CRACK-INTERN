class Solution {
public:
    const int mod=1e9+7;

    int rangeSum(vector<int>& nums, int x, int left, int right) {
        vector<int>vec;
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum+=nums[j];
                vec.push_back(sum);
            }
        }
        sort(vec.begin(),vec.end());
        left--;
        right--;

        int ans=0;
        for(int i=left;i<=right;i++)ans=(ans+vec[i])%mod;
        return ans%mod;
    }
};