struct Node{
    Node* links[2];
    
    bool containKey(int bit)
    {
        return (links[bit]!=NULL);
    }
    Node* get(int bit){
        return links[bit];
    }
    void put(int bit,Node *node)
    {
        links[bit]=node;
    }
    
};
class Trie{
    private:Node* root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(int num){
        Node* node=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(!node->containKey(bit))
            {
                node->put(bit,new Node());
            }
                node=node->get(bit);
        }
    }
    
    int getMax(int num)
    {
        Node *node=root;
        int maxx=0;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(node->containKey(!bit))
            {
                maxx=maxx|(1<<i);
                node=node->get(!bit);
            }
            else
                node=node->get(bit);
        }
        return maxx;
    }
    
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& q) {
        sort(nums.begin(),nums.end());
        vector<pair<int,pair<int,int>>>vec;
        for(int i=0;i<q.size();i++)
        {
            vec.push_back({q[i][1],{q[i][0],i}});
        }
        sort(vec.begin(),vec.end());
        
        int qs=q.size();
        int idx=0;
        Trie trie;
        vector<int>ans(qs,0);
        for(int i=0;i<qs;i++)
        {
            int ai=vec[i].first;
            int xi=vec[i].second.first;
            int Qidx=vec[i].second.second;
            
            while(idx<nums.size() && nums[idx]<=ai)
            {
                trie.insert(nums[idx]);
                idx++;
            }
            if(idx==0)
                ans[Qidx]=-1;
            else
                ans[Qidx]=trie.getMax(xi);
        }
        return ans;
    }
};