/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
#include<bits/stdc++.h>
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int n=employees.size();
        unordered_map<int,vector<int>>adj;
        unordered_map<int,int>mp;

        for(int i=0;i<n;i++)
        {
            int node = employees[i]->id;
            int imp = employees[i]->importance;
            for(auto it:employees[i]->subordinates)
            {
                adj[node].push_back(it);
            }
            mp[node]=imp;
        }

        
        queue<int>pq;
        pq.push(id);

        int ans=0;
        while(!pq.empty())
        {
            int id=pq.front();
            pq.pop();

            ans+=mp[id];
            for(auto conn:adj[id])
            {
                 pq.push(conn);
            }
        }
        return ans;
    }
};