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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* temp=head,*pre;
        
        while(temp!=NULL){
            temp=temp->next;
            len++;
        }
        if(len == 0 || len == 1)
            return NULL;
        len = len-n+1;
        temp = head;
        int i = 1;
        pre = head;
        while(i<len){
            pre = temp;
            temp = temp->next;
            i++;
        }
        if(temp==head){
            temp = head->next;
            head->next = NULL;
            return temp;
        }
        pre->next = temp->next;
        return head;
    }
};