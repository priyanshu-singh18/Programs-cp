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
    
    void solve(TreeNode* node,int &sum){
        
        // sum = node->val + solve(node->right);
        // node->val = node->val + solve(node->right,sum);
         if(node->right ) solve(node->right,sum);
        sum = sum + node->val;
        node->val = sum;
        if(node->left)   solve(node->left,sum);
        
        
        
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        if(root==NULL)
            return root;
        solve(root,sum);
        return root;
      
        
        
    }
};