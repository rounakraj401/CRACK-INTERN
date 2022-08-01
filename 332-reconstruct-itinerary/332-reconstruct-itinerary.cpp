class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n=tickets.size();
        
       unordered_map<string , multiset<string>>adj;
       vector<string>ans;
        
        stack<string>st;
        st.push("JFK");
        for(int i=0;i<n;i++)
        {
            adj[tickets[i][0]].insert(tickets[i][1]);
        }
        
        while(!st.empty())
        {
            string s=st.top();
            if(adj[s].size()==0)
            {
                ans.push_back(s);
                st.pop();
            }
            else
            {
                auto ss = adj[s].begin();
                st.push(*ss);
                
                adj[s].erase(ss);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};