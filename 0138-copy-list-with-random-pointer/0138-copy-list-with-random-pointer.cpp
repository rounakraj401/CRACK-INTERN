/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node*front=head;
        Node *it=head;
        
        while(it!=NULL)
        {
            front=it->next;
            
            Node *copy=new Node(it->val);
            
            it->next=copy;
            copy->next=front;
            it=front;
        }
        
        it=head;
        while(it!=NULL)
        {
            if(it->random!=NULL)
            {
                it->next->random=it->random->next;
            }
            it=it->next->next;
        }
        
        it=head;
        Node* dummy=new Node(-1);
        Node* tail=dummy;
        while(it!=NULL){
            tail->next=it->next;
            tail=tail->next;
            it->next=tail->next;
            it=it->next;
        }
        return dummy->next;
    }
};