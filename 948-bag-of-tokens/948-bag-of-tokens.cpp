class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
         sort(tokens.begin(),tokens.end());
             
        int cur=0;
        int l=0;
        int r=tokens.size()-1;
        int maxm=0;
        
        while(l<=r)
        {
            if(tokens[l]<=power)
            {
                power-=tokens[l];
                cur++;
                l++;
                
                maxm=max(maxm,cur);
            }
            else if(cur>=1)
            {
                power+=tokens[r];
                cur--;
                r--;
            }
            else
                break;
        }
        return maxm;
    }
};