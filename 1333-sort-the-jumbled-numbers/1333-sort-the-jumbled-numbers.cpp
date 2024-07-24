class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<vector<int>>vec;
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            int x=nums[i];
            string s="";
            
            if(x==0)
            {
               s=to_string(mapping[0])+s;
            }
            else
            {
             while(x)
             {
                int d=x%10;
                x/=10;
                s=to_string(mapping[d])+s;
             }
            }
            int xx=stoi(s);
            vec.push_back({xx,i,nums[i]});
        }
        vector<int>ans;
        sort(vec.begin(),vec.end());
        for(auto it:vec)
        {
            ans.push_back(it[2]);
        }
        return ans;
    }
};