/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* curr = root,*temp;
        stack <TreeNode*> sop;
        vector<int> ans;
        
        
        while(curr!=NULL || !sop.empty()){
            if(curr!=NULL){
                sop.push(curr);
                curr = curr->left;
            }
            else{
                temp = sop.top()->right;
                if(temp==NULL){
                    temp = sop.top();
                    sop.pop();

                    ans.push_back(temp->val);

                    while(!sop.empty() and temp == sop.top()->right){
                        temp= sop.top();
                        sop.pop();
                        ans.push_back(temp->val);
                    }
                }
                else
                    curr = temp;
        
            }
        }
        return ans;
    }
};