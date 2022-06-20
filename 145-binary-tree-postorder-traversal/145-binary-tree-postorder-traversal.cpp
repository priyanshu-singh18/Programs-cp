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
        vector<int> ans;
        
        if(root==NULL)
            return ans;
        
        stack<TreeNode*> s1,s2;
        TreeNode* temp;
        s1.push(root);
        
        
        
        while(!s1.empty()){
            temp = s1.top();
            s1.pop();
            
            s2.push(temp);
            
            if(temp->left != NULL)
                s1.push(temp->left);
            if(temp->right !=NULL)
                s1.push(temp->right);
        }
        
        
        while(!s2.empty()){
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        
        return ans;
    }
};