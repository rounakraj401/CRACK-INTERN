class Solution {
public:
    int minPartitions(string n) {
        int x=n.length();
        int maxm=0;
        for(int i=0;i<x;i++)
        {
            if((n[i]-'0')>maxm)maxm=n[i]-'0';
        }
        return maxm;
    }
};