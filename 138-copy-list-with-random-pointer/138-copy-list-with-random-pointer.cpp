/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return head;
        
        Node* temp = head , *newHead = NULL,*temp2;
        
        while(temp!=NULL){
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }
        temp = head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        
        temp = head;
        
        while(temp!=NULL){
            Node* p = temp->random;
            
            temp->next->random = (p == NULL) ? NULL : p->next;
            temp = temp->next->next;
        }
        
        temp = head , newHead = temp2 = temp->next;
        
        while(temp and temp2){
            temp->next = temp2->next;
            temp = temp->next;
            
            if(temp != NULL){
                temp2->next = temp->next;
                temp2 = temp2->next;
            }
        }
        
        return newHead;
    }
};