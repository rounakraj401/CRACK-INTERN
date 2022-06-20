class Solution {
public:
    int largestRectangleArea(vector<int>& hi) {
        int n=hi.size();
        stack<int>s;
        vector<int>left(n);
        vector<int>right(n);
        
        for(int i=0;i<n;i++)
        {
           while(!s.empty() && hi[s.top()]>=hi[i])s.pop();
           
            if(s.empty())left[i]=0;
            else
                left[i]=s.top()+1;
            s.push(i);
        }
        
        while(!s.empty())s.pop();
        
        for(int i=n-1;i>=0;i--)
        {
           while(!s.empty() && hi[s.top()]>=hi[i])s.pop();
           
            if(s.empty())right[i]=n-1;
            else
                right[i]=s.top()-1;
            
            s.push(i);
        }
        
        int maxm=0;
        for(int i=0;i<n;i++)
        {
            maxm=max(maxm,((right[i]-left[i]+1)*hi[i]));
        }
        return maxm;
    }
};