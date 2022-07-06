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
    ListNode* reverse(ListNode* head)
    {
        if(head==NULL || head->next==NULL)return head;
        ListNode *prev=NULL;
        ListNode *cur=head;
        ListNode* nex=head->next;
        
        while(cur!=NULL)
        {
            cur->next=prev;
            prev=cur;
            cur=nex;
            if(nex!=NULL)nex=nex->next;
        }
        return prev;  
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode*fast=head;
        
        while(fast->next!=NULL && fast->next->next!=NULL)  // change in condt because we want node just before of the middle one
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        slow->next=reverse(slow->next);
        ListNode* start=head;
        ListNode* mid=slow->next;
        while(mid!=NULL)
        {
            if(start->val!=mid->val)return false;
            start=start->next;
            mid=mid->next;
        }
        return true;
    }
    
};