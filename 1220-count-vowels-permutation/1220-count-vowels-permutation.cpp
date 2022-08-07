class Solution {
public:
    
// According to question characters associates with
// a: e
// e: a i
// i: a e o u
// o: i u
// u: a
// therefor after combining all associations characters associates with
// a-> e i u
// e-> a i
// i-> e o
// o-> i
// u-> i o
    const int mod=1e9+7;
    
    int countVowelPermutation(int n) {
        long long int a=1,e=1,i=1,o=1,u=1;
        long long int ans=0;
        
        for(int k=1;k<n;k++)
        {
            long long int a1=(e+i+u)%mod;
            long long int e1=(a+i)%mod;
            long long int i1=(e+o)%mod;
            long long int o1=(i)%mod;
            long long int u1=(i+o)%mod;
            
            a=a1;
            e=e1;
            i=i1;
            o=o1;
            u=u1;
        }
        
        return (a+e+i+o+u)%mod;
    }
};