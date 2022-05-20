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
    bool isPalindrome(ListNode* head) {
        if(head->next ==NULL)
            return true;
        ListNode* slow=head, *fast=head,*prev=NULL,*p;
        while(fast!=NULL and fast->next!=NULL){
            prev=slow;
            slow = slow->next;
            fast = fast->next->next;
            
        }
        if(fast!=NULL and fast->next==NULL)
            slow = slow->next;
            
        prev->next=NULL;
        p = head;
            ListNode* newHead = NULL;
        while(1){
            if(p==NULL){
                break;
            }
            ListNode* next = p->next;
            p->next = newHead;
            newHead = p;
            p = next;
        }
        p = newHead;
        while(slow!=NULL and p){
            if(slow->val != p->val)
                return false;
            slow = slow->next;
            p = p->next;
            
            
        }
        return true;
    }
};