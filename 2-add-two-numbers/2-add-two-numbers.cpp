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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy=new ListNode(-1);
        dummy->next=NULL;
        ListNode *temp=dummy;
        int sum=0;
        int car=0;
        
        
        while(l1!=NULL || l2!=NULL)
        {
            sum=0;
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=car;
            
            if(sum>=10)
            {
                car=sum/10;
                sum%=10;
            }
            else
            {
                car=0;
            }
            
            ListNode *neww=new ListNode(sum);
            temp->next=neww;
            temp=temp->next;
        }
        if(car)
        {
            ListNode* last=new ListNode(car);
            temp->next=last;
        }
        return dummy->next;
    }
};