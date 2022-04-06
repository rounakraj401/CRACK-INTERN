class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        
            int i=1;
            while(i<n)
            {
                int up=0;
                int down=0;
                
                while(i<n && arr[i-1]<arr[i]){i++;up++;}
                while(i<n && arr[i-1]>arr[i]){i++;down++;}
                
                if(up>0 && down>0)ans=max(ans,up+down+1);
                
                while (i <n && arr[i - 1] == arr[i]) i++;
            }
            return ans;
        }
};