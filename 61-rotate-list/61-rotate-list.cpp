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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL or head->next==NULL)
            return head;
        
        int n = 0;
        ListNode* p = head, *temp,*last;
        
        while(p!=NULL){
            n++;
            last = p;
            p=p->next;
        }
        k = k% n ;
        if(!k)
            return head;
        p = head;
        while(n-k>1){
            p = p->next;
            n--;
        }
        temp = p->next;
        p->next = NULL;
        last->next = head;
        return temp;
    }
};