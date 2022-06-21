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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
    
    if(root==NULL)
        return ans;
      map<int, map<int , multiset<int>>> mop;
    queue<pair<TreeNode*,pair<int,int>>> qop;
    
    qop.push({root,{0,0}});
      
    while(!qop.empty()){
        int n = qop.size();
        while(n--){
            auto it = qop.front();
            qop.pop();
            
            TreeNode* temp = it.first;
            int v = it.second.first , l = it.second.second;
            
            mop[v][l].insert(temp->val);
            
            if(temp->left){
                qop.push({temp->left,{v-1,l+1}});
            }
            if(temp->right){
                qop.push({temp->right,{v+1,l+1}});
            }
        }
    }
    
    for(auto p : mop){
        vector<int> col;
        for(auto q : p.second){
            col.insert( col.end(), q.second.begin(),q.second.end());
        }
        ans.push_back(col);
    }
    
    return ans;
    }
};