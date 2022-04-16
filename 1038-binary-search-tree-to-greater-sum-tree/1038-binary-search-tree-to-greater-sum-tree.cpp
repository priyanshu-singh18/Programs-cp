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
    int sum;
    
    void solve(TreeNode* node){
        if(node->right)
            solve(node->right);
        sum+=node->val;
        node->val=sum;
        if(node->left)
            solve(node->left);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        if(root==NULL)
            return root;
        sum=0;
        solve(root);
        return root;
    }
};