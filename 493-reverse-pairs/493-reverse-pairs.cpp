class Solution {
public:
long long int merge(vector<int>&arr,vector<int>&temp,int left,int mid,int right)
{
    long long int cnt=0;
    int j=mid+1;
    
    for(int i=left;i<=mid;i++)
    {
        while(j<=right && arr[i]>2LL*arr[j])
            j++;
        
        cnt+=(j-mid-1);
    }
    
    int i=left;
    j=mid+1;
    
    vector<int>t;
    
    while(i<=mid && j<=right)
    {
        if(arr[i]<=arr[j])
        {
            t.push_back(arr[i++]);
        }
        else
        {
            t.push_back(arr[j++]);
        }
    }
    
    while(i<=mid)t.push_back(arr[i++]);
    while(j<=right)t.push_back(arr[j++]);
    
    for(int i=left;i<=right;i++)arr[i]=t[i-left];
    return cnt;
}

long long int mergesort(vector<int>&arr,vector<int>&temp,int left,int right)
{
    long long int cnt=0;
    int mid;
    if(right>left)
    {
        mid=(left+right)/2;
        
        cnt+=mergesort(arr,temp,left,mid);
        cnt+=mergesort(arr,temp,mid+1,right);
        
        cnt+=merge(arr,temp,left,mid,right);
    }
    return cnt;
}
    
    int reversePairs(vector<int>& arr) {
       int n=arr.size();
       vector<int>temp(n);
       int ans=mergesort(arr,temp,0,n-1);
       return ans; 
    }
};