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
    ListNode* reverse(ListNode* node)
    {
        ListNode* curr=node;
        ListNode* prev=NULL;
        while(curr!=NULL)
        {
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    ListNode* middle(ListNode* node)
    {
        ListNode* fast=node;
        ListNode* slow=node;
        while(fast!=NULL&&fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    bool isPalindrome(ListNode* head) {
    
        ListNode* shead=reverse(middle(head));
        while(head!=NULL&&shead!=NULL)
        {
            if(head->val!=shead->val)
            return false;
            head=head->next;
            shead=shead->next;
        }
        return true;
    }
};