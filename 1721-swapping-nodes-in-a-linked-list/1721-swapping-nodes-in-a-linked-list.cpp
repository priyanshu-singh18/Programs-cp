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
    ListNode* swapNodes(ListNode* head, int k) {
        int count = 0;
        ListNode* p1=head,*p2=head,*temp;
        
        while(p1!=NULL){
            if(count<k){
                temp = p1;
                p1 = p1->next; 
            }
            else{
                p2 = p2->next;
                p1 = p1->next;
            }
            count++;
        }
        int op;
        
        op = temp->val;
        temp->val = p2->val;
        p2->val = op;
        
        
        return head;
    }
};