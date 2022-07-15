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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if(root==NULL)
            return ans;
        
        queue<TreeNode*> qop;
        qop.push(root);
        
        while(!qop.empty()){
            int n = qop.size();
            vector<int> v;
            while(n--){
                TreeNode* temp = qop.front();
                qop.pop();
                
                v.push_back(temp->val);
                
                if(temp->left)
                    qop.push(temp->left);
                if(temp->right)
                    qop.push(temp->right);
            }
            
            ans.push_back(v);
        }
        return ans;
    }
};