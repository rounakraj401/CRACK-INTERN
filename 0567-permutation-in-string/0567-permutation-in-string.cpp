class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        multiset<char>st1,st2;
        for(auto it:s1)
        st1.insert(it);
        
        int n=s1.size();
        if(n>s2.size())return false;
        
        for(int i=0;i<n;i++)st2.insert(s2[i]);
        
        int i=n;
        while(i<s2.size())
        {
             if(st1==st2)return true;
             st2.insert(s2[i]);
             st2.erase(st2.find(s2[i-n]));
            
            i++;
        }
        if(st2==st1)return true;
        return false;
    }
};