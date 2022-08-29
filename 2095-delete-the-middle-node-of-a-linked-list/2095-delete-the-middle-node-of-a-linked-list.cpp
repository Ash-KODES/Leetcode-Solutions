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
    ListNode* middleNode(ListNode* head)
    {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL&&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* deleteMiddle(ListNode* head)
    {
        if(head->next==NULL)
        return NULL;
        ListNode* mid=middleNode(head);
        if(mid->next==NULL)
        {
            head->next=NULL;
            return head;
        }
        mid->val=mid->next->val;
        mid->next=mid->next->next;
        return head;
    }
};