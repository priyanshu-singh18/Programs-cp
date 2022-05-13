/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
          return NULL;  
        queue<Node*> qop;
        qop.push(root);
        
        while(!qop.empty()){
            int n = qop.size();
            Node* pre = NULL;
            
            
            while(n--){
                Node* op = qop.front();
                qop.pop();
                
                op->next = pre;
                pre = op;
                
                if(op->right)
                    qop.push(op->right);
                if(op->left)
                    qop.push(op->left);
            }
        }
        return root;
    }
};