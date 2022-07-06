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
//         ListNode* temp=head;
//         ListNode* start=head;
        
//         if(head==NULL)return head;
        
//         while(temp->next!=NULL)
//         {
//           while(temp->val==start->val)
//           {
//             temp=temp->next;
//               if(temp==NULL){
//                   start->next=NULL;
//                   return head;
//               }
//           }
//           start->next=temp;
//           start=temp;
//         }
//         return head;
//     }
        
        if(head==NULL || head->next==NULL)return head;
        ListNode *newh=deleteDuplicates(head->next);
        if(newh->val==head->val)return newh;
        else
        {
            head->next=newh;
            return head;
        }
    }
};