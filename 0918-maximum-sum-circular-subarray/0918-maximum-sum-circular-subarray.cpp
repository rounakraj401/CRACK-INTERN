class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxs=INT_MIN,mins=INT_MAX,tots=0,curs1=0,curs2=0;
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            tots+=nums[i];
            curs1+=nums[i];
            curs2+=nums[i];
            
            maxs=max(maxs,curs1);
            mins=min(mins,curs2);
            
            if(curs1<0)curs1=0;
            if(curs2>0)curs2=0;
        }
        if(tots==mins)
            return maxs;
        
        return max(maxs,tots-mins);
    }
};