class LRUCache {
public:
    typedef struct node {
        node *prev, *next;
        int key, val;
        
        node(int key, int val) {
            this->prev = NULL;
            this->next = NULL;
            this->key = key;
            this->val = val;
        }
    } node;
    
    node *head=new node(-1,-1);
    node *tail=new node(-1,-1);
    
    int cap;
    unordered_map<int ,node*>m;
    
    LRUCache(int capacity) {
       cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addnode(node *neww)
    {
        node* temp=head->next;
        neww->next=temp;
        neww->prev=head;
        head->next=neww;
        temp->prev=neww;
    }
    void deletenode(node * neww)
    {
        node*delp=neww->prev;
        node* deln=neww->next;
        delp->next=deln;
        deln->prev=delp;
    }
    int get(int key1) {
        if(m.find(key1)!=m.end())
        {
            node* resnode=m[key1];
            int res=resnode->val;
            m.erase(key1);
            deletenode(resnode);
            addnode(resnode);
            
            m[key1]=head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key1, int value) {
        if(m.find(key1)!=m.end())
        {
            node* exist=m[key1];
            m.erase(key1);
            deletenode(exist);
        }
        if(m.size()==cap)
        {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key1,value));
        m[key1]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */