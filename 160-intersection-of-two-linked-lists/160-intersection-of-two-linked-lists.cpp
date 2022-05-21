/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = 0, l2 = 0;
        ListNode *p1=headA, *p2 = headB,*temp;
        
        while(p1!=NULL){
            l1++;
            p1 = p1->next;
        }
        
        while(p2!=NULL){
            l2++;
            p2 = p2->next;
        }
        p1 = headA,p2 = headB;
        if(l1>l2){
            while(l1-l2)
                p1=p1->next,l1--;
        }
        else{
            while(l2-l1)
                p2 = p2->next,l2--;
        }
        
        while(p1){
            if(p1==p2){
                temp=p1;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return temp;
    }
};