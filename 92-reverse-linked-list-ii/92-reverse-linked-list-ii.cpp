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
    
    // ListNode* reverseLL(ListNode* head , ListNode* newNode, ListNode* og, int& cnt, int right){
//         if(cnt == right + 1){
//             return newNode;
//         }
        
//         ListNode* next = head->next;
//         if(cnt == right)
//             og = head;
//         head->next = newNode ; 
//         cnt++;
//         return reverseLL(next , newNode , og , cnt , right);
    // }
    
    
    ListNode* reverseLL(ListNode* head , ListNode* newNode){
        if(head ==NULL)
            return newNode;
        
        ListNode* next = head->next;
        head->next = newNode;
        return reverseLL(next , head);
    }
    
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
//         ListNode* prev,*og, *p = head;
//         int cnt = 1;
        
//         while(cnt!=left){
//             prev = p;
//             p = p->next;    
//             cnt++;
//         }
//         prev->next  = reverseLL(p , NULL , og, cnt, right);
        
//         return head;
        
        if(left == right)
            return head;
        
        ListNode* last = head , *first ,*prev , *after;
        
        int cnt = 1 ; 
        while(cnt!=right){
            if(cnt == left-1)
                prev = last;
            if(cnt == left)
                first = last ; 
            last = last->next;
            
            cnt++;
        }
        
        after = last->next;
        last->next = NULL;
        ListNode* returned = reverseLL(first , NULL);
        
        if(first == head){
            head->next = after;
            return returned;
        }
        
        prev ->next = returned;
        first->next = after;
        
        
        return head ; 
    }
};