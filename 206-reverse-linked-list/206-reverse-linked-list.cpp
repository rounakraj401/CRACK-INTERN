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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)return NULL;
        ListNode* prev=NULL,*temp=head,*nex=head->next;
        
        while(temp!=NULL)
        {
            temp->next=prev;
            prev=temp;
            temp=nex;
            if(nex!=NULL)nex=nex->next;
        }
        return prev;
    }
};