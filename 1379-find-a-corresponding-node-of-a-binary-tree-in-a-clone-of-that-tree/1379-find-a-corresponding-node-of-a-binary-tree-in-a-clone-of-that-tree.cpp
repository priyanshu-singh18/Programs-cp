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
    TreeNode* ans ;
    
    void trav(TreeNode* oh, TreeNode* ch, TreeNode* target){
        if(oh){
            if(oh == target){
                ans = ch;
                return; 
            }
            trav(oh->left,ch->left,target);
            trav(oh->right,ch->right,target);
        }
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        trav(original,cloned, target);
        return ans;
    }
};