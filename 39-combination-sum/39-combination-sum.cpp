class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int i,int s ,int sum , int n , vector<int>& candidates, set<vector<int>>& sop, vector<int>& temp){
        if(i==n || s>=sum){
            if(s==sum){
                // sop.insert(temp);
                ans.push_back(temp);
            }
            return;
        }
        
//           s+=candidates[i];
//         temp.push_back(candidates[i]);
//         solve(i,s,sum,n,candidates,sop,temp);
        
//         s-=candidates[i];
//         temp.pop_back();
        
        
//         s+=candidates[i];
//         temp.push_back(candidates[i]);
//         solve(i+1,s,sum,n,candidates,sop,temp);
//         s-=candidates[i];
//         temp.pop_back();
//         solve(i+1,s,sum,n,candidates,sop,temp);
        
          solve(i+1,s,sum,n,candidates,sop,temp);
          s+=candidates[i];
        temp.push_back(candidates[i]);
        
        solve(i,s,sum,n,candidates,sop,temp);
        s-=candidates[i];
        temp.pop_back();
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        set<vector<int>> sop;
        int n = candidates.size();
        vector<int> temp;
        solve(0,0,target,n,candidates,sop,temp);
        // vector<vector<int>> ans(sop.begin(),sop.end());
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};