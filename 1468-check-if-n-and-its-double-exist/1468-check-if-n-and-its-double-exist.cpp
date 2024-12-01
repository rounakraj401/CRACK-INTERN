class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int>st;
        
        for(auto it:arr)
        {
            int n1=it*2;
            int n2=abs(it)%2==0? it/2 : INT_MAX;

            if(st.count(n1)>0 || st.count(n2)>0)
            return true;

            st.insert(it);
        }
        return false;
    }
};