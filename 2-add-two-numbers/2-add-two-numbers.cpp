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
        ListNode* p , *head3 = new ListNode(0);
        int c=0;
        p = head3;
        
        while(c || l1 || l2){
            c+= (l1?l1->val:0 )+ (l2?l2->val:0);
            p->next = new ListNode(c%10);
            p = p->next;
            c/=10;
            
            if(l1) l1=l1->next;
            if(l2) l2 =l2->next;
        }
        return head3->next;
    }
};