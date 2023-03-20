class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int ss=flowerbed.size();
        
        int start=-1,end=-1;
        
        for(int i=0;i<ss;i++)
        {
            if(flowerbed[i]==1)
            {
                start=i;
                break;
            }
        }
        for(int i=ss-1;i>=0;i--)
        {
            if(flowerbed[i]==1)
            {
                end=i;
                break;
            }
        }
//        cout<<start<<" "<<end<<"\n";
        
        if(start==-1)
            return ceil(ss/2.0)>=n;
        
        int ans=0;
        if(start>1)ans+=ceil(start/2.0);
        if(ss-1-end>1)ans+=ceil((ss-1-end)/2.0);
        
//        cout<<ans<<"\n";
        
        int ptr1=0;int ptr2=start;
        
        for(int i=start+1;i<=end;i++)
        {
            if(flowerbed[i]==1 && ptr1==0)
            {
                ptr1=i;
                ans+=(ptr1-ptr2-2)/2;
  //              cout<<ptr1<<" "<<ptr2<<" "<<ans<<"\n";
            }
            else if(flowerbed[i]==1 && ptr1!=0)
            {
                ptr2=ptr1;
                ptr1=i;
                
                ans+=(ptr1-ptr2-2)/2;
            }
        }
        return ans>=n;
        
    }
};