class Solution {
public:
    int find_par(int x,vector<int>&parent)
    {
        if(parent[x]==-1)
            return x;
        return parent[x]=find_par(parent[x],parent);
    }
    
    void unionn(int a,int b,vector<int>&parent)
    {
        a=find_par(a,parent);
        b=find_par(b,parent);
        
        if(a!=b)
        {
            if(a<=b)
                parent[b]=a;
            else
                parent[a]=b;
        }
    }
    string smallestEquivalentString(string s1, string s2, string base) {
        vector<pair<char,set<char>>>vec;
        int n=s1.length();
        
        vector<int>parent(27);
        for(int i=0;i<27;i++)
        {
            parent[i]=-1;
        }
        
        for(int i=0;i<n;i++)
        {
            int ch1=s1[i]-'a';
            int ch2=s2[i]-'a';
            
            unionn(ch1,ch2,parent);
        }
        
        string ans="";
        for(int i=0;i<base.size();i++)
        {
//            cout<<"OM\n";
            ans+=(find_par(base[i]-'a',parent)+'a');
        }
        return ans;
        
    }
};