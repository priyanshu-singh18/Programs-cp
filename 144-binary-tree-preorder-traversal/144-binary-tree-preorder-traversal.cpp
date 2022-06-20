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
    vector<int> preorderTraversal(TreeNode* root) {
            stack<TreeNode*> sop;
    sop.push(root);
    vector<int> ans;
      TreeNode* temp;
    while(!sop.empty()){
        
         temp = sop.top();
        sop.pop();
        
        if(temp!=NULL){
            ans.push_back(temp->val);
            sop.push(temp->right);
        
            sop.push(temp->left);
        }
    }
    return ans;
    }
};