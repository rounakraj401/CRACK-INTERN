class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int t=target-'a';
        int n=letters.size();
        vector<int>vec(n);
        for(int i=0;i<n;i++)
           vec[i]=letters[i]-'a';
        
        if(t>vec[n-1])return vec[0]+'a';
        
        int l=0;
        int h=n-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;

            if(t>=vec[mid])
                l=(mid+1);
            else if(t<vec[mid])
                h=(mid-1);
        }
        if(l>h)
        return vec[l%n]+'a';
        
        return 0;
    }
};