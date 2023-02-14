/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>vec;
        if(head==NULL)
        {
            while(k--)
                vec.push_back(NULL);
            return vec;
        }    
        
        int cnt=1;
        ListNode* prev;
        ListNode* temp=head;
        
        while(temp->next!=NULL)
        {
            temp=temp->next;
            cnt++;
        }
        if(cnt<=k)
        {
            while(head!=NULL)
            {
                k--;
                temp=head->next;
                head->next=NULL;
                vec.push_back(head);
                
                head=temp;
            }
            while(k--)
            {
                vec.push_back(NULL);
            }
            return vec;
        }
        
        int x=cnt/k;
        int rem=cnt%k;
        
        ListNode* ptr1=head;
        ListNode* ptr2=head;
        
        for(int i=0;i<rem;i++)
        {
            ptr2=ptr1;
            for(int j=0;j<x;j++)
            {
                ptr2=ptr2->next;
            }
            vec.push_back(ptr1);
            ptr1=ptr2->next;
            ptr2->next=NULL;
        }
        
        for(int i=0;i<k-rem;i++)
        {
            ptr2=ptr1;
            for(int j=0;j<x-1;j++)
            {
                ptr2=ptr2->next;
            }
            vec.push_back(ptr1);
            ptr1=ptr2->next;
            ptr2->next=NULL;
        }  
        return vec;
    }
};