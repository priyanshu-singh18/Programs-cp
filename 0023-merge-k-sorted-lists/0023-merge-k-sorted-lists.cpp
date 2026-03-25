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
        priority_queue<pair<int , ListNode*> , vector<pair<int,ListNode*>> , greater<pair<int,ListNode*>>> pq;

        for(ListNode* ll : lists){
            while(ll){
                pq.push({ll->val , ll});
                ll = ll->next;
            }
        }
        if(pq.empty()){
            return nullptr;
        }
        ListNode* first = pq.top().second;
        pq.pop();
        ListNode* last = first;

        while(!pq.empty()){
            pair<int , ListNode*> temp = pq.top();
            pq.pop();

            last->next = temp.second;
            last = temp.second;
        }
        return first;
    }
};
