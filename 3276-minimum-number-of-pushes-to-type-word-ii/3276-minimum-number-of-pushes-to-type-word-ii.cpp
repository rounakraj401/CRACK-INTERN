class Solution {
public:
    int minimumPushes(string word) {
       map<char,int>mp;
       for(auto it:word)
       {
         mp[it]++;
       }
       vector<pair<int,char>>vec;
       for(auto it:mp)
       {
          vec.push_back({it.second,it.first});
       }

       sort(vec.rbegin(),vec.rend());

       int ans=0;
       int cnt=0;
       int mul=1;

       for(auto it:vec)
       {
           int num=it.first;

           cnt++;

           ans+=(num*mul);
           if(cnt%8==0)
           {
              cnt=0;
              mul++;
           }
       }
       return ans;
    }
};