class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxm=*max_element(candies.begin(),candies.end());
        
        int n=candies.size();
        vector<bool>vec(n);
        for(int i=0;i<n;i++)
        {
            if(candies[i]+extraCandies>=maxm)
                vec[i]=true;
            else
                vec[i]=false;
        }
        return vec;
    }
};