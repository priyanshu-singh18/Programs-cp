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
        if(head == NULL or head->next==NULL)
            return head;
        
        ListNode* starter, *p =head;
        ListNode* dummy = new ListNode(0);
        starter = dummy;
        dummy->next = head;
        
        while(p!=NULL and p->val<x){
            if(p->next and p->next->val>=x and starter == dummy){
                starter = p;
                break;
            }
            
            p = p->next;
        }
   
        if(head ->val >=x)
            starter = dummy;
        
        while(p!=NULL){
            if(p->next and p->next->val < x){
                ListNode*  next = p->next->next,*temp = starter->next;
                starter->next = p->next;
                p->next->next = temp;
                starter = starter->next;
                p->next = next;
            }
            else
            p = p->next;
        }
        return dummy->next;
    }
};