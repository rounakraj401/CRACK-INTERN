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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp=head;
        if(head==NULL || head->next==NULL)return head;
        
        while(temp->next!=NULL)
        {
            if(temp->val==temp->next->val)
            {
                ListNode *del=temp->next;
                temp->next=del->next;
                delete del;
            }
            else
            {
                temp=temp->next;
            }
        }
        return head;
        
    
        //  RECURSIVE SOLUTION
    
        // if(head==NULL || head->next==NULL)return head;
        // ListNode *newh=deleteDuplicates(head->next);
        // if(newh->val==head->val)return newh;
        // else
        // {
        //     head->next=newh;
        //     return head;
        // }
    }
};