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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() ==1)
            return lists[0];
        
        priority_queue<int,vector<int> , greater<int>> pq;
        ListNode* temp;
        for(int i=0;i<lists.size();i++){
            temp = lists[i];
            // if(temp==NULL) continue;
            while(temp){
                pq.push(temp->val);
                temp=temp->next;
            }
        }
        
        ListNode* head=NULL;
        
        while(!pq.empty()){
            ListNode* newNode = new ListNode(pq.top());
            pq.pop();
            
            if(head==NULL){
                head = newNode;
                temp = head;
            }else{
            temp->next = newNode;
            temp = temp->next;
                
            }
        }
        return head;
    }
};