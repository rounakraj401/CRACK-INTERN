class Solution {
public:
    int check(int val, vector<int>& arr, int target) {
    int valSum = 0;
    for(auto ele: arr) {
        valSum += min(val, ele);
    }
    
    return abs(valSum - target);
}

int findBestValue(vector<int>& arr, int target) {
    int low = 0, high = 1e5 + 2;
    
    while(low < high) {
        int mid = low + (high - low) / 2;
        
        if(check(mid, arr, target) > check(mid + 1, arr, target))
            low = mid + 1;

        else 
            high = mid;
    }
    
    return low;
  }
};