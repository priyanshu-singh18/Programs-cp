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
    
    void solve(TreeNode* node, vector<int>& inorder){
        if(node==NULL)
            return;
        solve(node->left,inorder);
        inorder.push_back(node->val);
        solve(node->right,inorder);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> inorder;
        solve(root,inorder);
        TreeNode* p=NULL, *temp;
        for(auto x : inorder){
            TreeNode* newNode = new TreeNode(x);
            newNode->left = NULL;
            newNode->right = NULL;
            if(p==NULL){
                p = newNode;
                temp = p;
                
            }
            else{
                temp->right = newNode;
                temp=temp->right;
            }
        }
        // for(auto t : inorder)
        //     cout<<t<<" ";
        return p;
    }
};