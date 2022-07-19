class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        
        string tar="123450";
        string start="";
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                start+=to_string(board[i][j]);
            }
        }
        
        queue<string>q;
        q.push(start);
        
        set<string>s;
        int level=0;
        
        vector<vector<int>>rev={{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        
        while(!q.empty())
        {
            int x=q.size();
            while(x--)
            {
                string temp=q.front();
                q.pop();
                
                if(temp==tar)
                {
                    return level;
                }
                
                int idx=-1;
                for(int i=0;i<temp.size();i++)
                {
                    if(temp[i]=='0')
                    {
                        idx=i;
                        break;
                    }
                }
                vector<int>vec=rev[idx];
                
                for(int i=0;i<vec.size();i++)
                {
                    string s1=temp;
                    swap(s1[idx],s1[vec[i]]);
                    if(s.find(s1)==s.end())
                    {
                        s.insert(s1);
                        q.push(s1);
                    }
                }
            }
            level++;
        }
       return -1;
    }
};