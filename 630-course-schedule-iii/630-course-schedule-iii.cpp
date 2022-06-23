class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        int n=courses.size();
        priority_queue<int>q;
        
        sort(courses.begin(),courses.end(),cmp);
        
        int sum=0;
        for(auto it:courses)
        {
            sum+=it[0];
            q.push(it[0]);
            
            if(sum>it[1])
            {
                sum-=q.top();
                q.pop();
            }
        }
        return q.size();
    }
};