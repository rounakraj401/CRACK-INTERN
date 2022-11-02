class Solution {
public:
    
    
    int minMutation(string start, string end, vector<string>& bank) {
        queue<pair<string,int>>pq;
        int n=bank.size();
        
        vector<char>arr;
        arr.push_back('A');
        arr.push_back('T');
        arr.push_back('G');
        arr.push_back('C');
        
        unordered_set<string>st;
        for(auto it:bank)
        {
            st.insert(it);
        }
        
        if(!st.count(end))
            return -1;
        
        int len=1;
        pq.push({start,len});
        
        while(!pq.empty())
        {
            string s=pq.front().first;
            int len=pq.front().second;
            pq.pop();
            
            string temp=s;
            for(int i=0;i<s.length();i++)
            {
                char ch=temp[i];
                for(auto it:arr)
                {
                    temp[i]=it;
                    if(temp==end)return len;
                    
                    if(temp!=s && st.count(temp))
                    pq.push({temp,len+1});
                }
                temp[i]=ch;
            }
        }
        return -1;
        
    }
};