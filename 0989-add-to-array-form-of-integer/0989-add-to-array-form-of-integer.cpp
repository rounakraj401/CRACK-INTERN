class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        stack<int>st;
        int carry=0;
        
        int n=num.size();
        for(int i=n-1;i>=0;i--)
        {
            int x=num[i]+k%10+carry;
            k/=10;
            
            st.push(x%10);
            if(x>=10)
                carry=x/10;
            else
                carry=0;
        }
        while(k>0)
        {
            int x=k%10+carry;
            
            if(x>=10)
                carry=x/10;
            else
                carry=0;
            
            st.push(x%10);
            
            k/=10;
        }
        if(carry!=0)st.push(carry);
        
        vector<int>ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};