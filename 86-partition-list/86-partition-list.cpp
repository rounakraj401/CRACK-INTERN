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
    ListNode* partition(ListNode* head, int x) {
         ListNode* small=new ListNode(-1);
         ListNode* big=new ListNode(-1);
        
        ListNode* small_head=small;
        ListNode* big_head=big;
        
        while(head)
        {
            if(head->val<x)
            {
                small->next=head;
                head=head->next;
                small=small->next;
                small->next=NULL;
            }
            else
            {
                big->next=head;
                head=head->next;
                big=big->next;
                big->next=NULL;
            }
        }
        small->next=big_head->next;
        return small_head->next;
    }
};