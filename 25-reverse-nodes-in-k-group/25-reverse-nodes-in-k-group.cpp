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
    
    ListNode* reverse(ListNode* head, ListNode* newHead){
        if(head==NULL)
            return newHead ;
        ListNode* next = head->next;
        head->next = newHead;
        return reverse(next, head);
    }
    
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 0;
        ListNode* p = head,*op=NULL,*prev,*ans;
        
        while(p!=NULL){
            p=p->next;
            n++;
        }
        ListNode* p1 = head, *p2 = head;
        
        while(n>=k){
            int i = 1;
           while(i<k){
               i++;
               p2 = p2->next;
           }
            ListNode* next = p2->next;
            if(p1==head)
                ans = p2;
            p2->next = NULL;
            p = reverse(p1,NULL);
            p1->next = next;
            if(p1!=head)
            prev->next = p;
            prev = p1;
            p1 = p2 = next;
            n-=k;
        }
        return ans;
    }
};