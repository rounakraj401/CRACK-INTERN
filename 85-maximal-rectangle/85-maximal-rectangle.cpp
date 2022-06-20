class Solution {
public:
    int fun(vector<int>&hi)
    {
        int n=hi.size();
        stack<int>st;
        int maxm=0;
        
        for(int i=0;i<=n;i++)
        {
            while(!st.empty() && (i==n || hi[st.top()]>=hi[i]))
            {
                int height=hi[st.top()];
                st.pop();
                int width;
                if(st.empty())width=i;
                else
                    width=i-st.top()-1;
                
                maxm=max(maxm,height*width);
            }
            st.push(i);
        }
        return maxm;
    }
    
    int maximalRectangle(vector<vector<char>>& mat) {
        
        int n=mat.size();
        int m=mat[0].size();
        vector<int>temp(m,0);
        int maxm=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]=='1')
                    temp[j]+=1;
                else
                    temp[j]=0;
            }
            int ans=fun(temp);
            maxm=max(maxm,ans);
        }
        return maxm;
    }
};