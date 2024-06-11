class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>mp;
        for(auto it:arr1)mp[it]++;
        vector<int>vec;

        for(int i=0;i<arr2.size();i++)
        {
            while(mp[arr2[i]]--)
            {
                vec.push_back(arr2[i]);
            }
            mp.erase(arr2[i]);
        }
        for(auto it:mp)
        {
            int num=it.first;
            int freq=it.second;

            while(freq--)
            {
                vec.push_back(num);
            }
            mp.erase(num);
        }
        return vec;
    }
};