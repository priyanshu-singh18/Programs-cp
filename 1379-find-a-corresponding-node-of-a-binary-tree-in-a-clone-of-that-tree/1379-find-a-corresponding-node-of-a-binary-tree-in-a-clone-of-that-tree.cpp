/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*> qop, q;
        qop.push(original);
        
        int flag = 0, count = 0;
        
        while(!qop.empty()){
            int n = qop.size();
            
            while(n--){
                TreeNode* node = qop.front();
                qop.pop();
                count++;
                if(node == target){
                    flag = 1;
                    break;
                }
                if(node->left)
                    qop.push(node->left);
                if(node->right)
                    qop.push(node->right);
            }
            if(flag==1)
                break;
        }
        flag = 0;
        q.push(cloned);
        int cnt = 0;
        TreeNode* ans;
        
        while(!q.empty()){
            int n = q.size();
            
            while(n--){
                TreeNode* op = q.front();
                q.pop();
                cnt++;
                if(cnt == count){
                    flag=1;
                    ans = op;
                    break;
                }
                if(op->left)
                    q.push(op->left);
                if(op->right)
                    q.push(op->right);
            }
            if(flag == 1)
                break;
        }
        return ans;
    }
};