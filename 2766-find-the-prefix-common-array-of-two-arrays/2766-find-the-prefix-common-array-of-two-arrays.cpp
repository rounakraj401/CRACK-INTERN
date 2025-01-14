class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        set<int>st;
        int n=A.size();
        int ans=0;
        vector<int>vec;
        for(int i=0;i<n;i++)
        {
            st.insert(A[i]);
            st.insert(B[i]);

            ans=((i+1)*2)-st.size();
            vec.push_back(ans);
        }
        return vec;
    }
};