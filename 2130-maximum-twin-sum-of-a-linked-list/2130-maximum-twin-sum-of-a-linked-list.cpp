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
    int pairSum(ListNode* head) {
        vector<int>vec;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            vec.push_back(temp->val);
            temp=temp->next;
        }
        int p1=0;
        int p2=vec.size()-1;
        int ans=INT_MIN;
        while(p1<=p2)
        {
            ans=max(ans,vec[p1]+vec[p2]);
            p1++;
            p2--;
        }
        return ans;
        
    }
};