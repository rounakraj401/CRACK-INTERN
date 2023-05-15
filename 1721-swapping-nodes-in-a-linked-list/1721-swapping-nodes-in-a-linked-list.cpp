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
    ListNode* swapNodes(ListNode* head, int k) {
            ListNode* cur=head;
            int cnt=1;
            ListNode* left=head;
            ListNode* right=head;
            
            while(cur!=NULL)
            { 
                if(cnt<k)left=left->next;
                if(cnt>k)right=right->next;
                
                cnt++;
                cur=cur->next;
            }
            int xx=left->val;
            left->val=right->val;
            right->val=xx;
            
            return head;
    }
};