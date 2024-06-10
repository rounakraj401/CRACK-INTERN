class Solution {
public:
    int heightChecker(vector<int>& heights) {
        
        vector<int> temp(begin(heights), end(heights));
        sort(begin(heights), end(heights));

        int count = 0;
        for(int i=0; i<heights.size(); i++){
            if(temp[i] != heights[i]){
                count++;
            }
        }

        return count;
    }
};