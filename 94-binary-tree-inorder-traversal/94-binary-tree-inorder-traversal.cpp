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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> sop;
        TreeNode* temp=root;
        vector<int> ans;
        
        while(1){
            if(temp!=NULL){
                sop.push(temp);
                temp=temp->left;
            }
            else{
                if(sop.empty())
                    break;
                temp = sop.top();
                sop.pop();
                
                ans.push_back(temp->val);
                temp=temp->right;
            }
        }
        return ans;
    }
};