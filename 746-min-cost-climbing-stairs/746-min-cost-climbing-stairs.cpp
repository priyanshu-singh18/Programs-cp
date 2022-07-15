class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        int curi , prev = cost[1] ,prev2=cost[0];
        
        for(int i=2;i<n;i++){
            curi = cost[i] + min(prev,prev2);
            prev2 = prev;
            prev = curi;
        }
        return min(prev,prev2);
    }
};