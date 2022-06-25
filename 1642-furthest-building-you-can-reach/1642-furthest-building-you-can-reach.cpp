class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = heights.size();
        int ans = 0,i=0;
        for(i=0;i<heights.size()-1;i++){
            int need = heights[i+1] - heights[i];
            
            if(need<0){
                ans=i+1;
                continue;
                
            }
            else{
                if(ladders > 0){
                    pq.push(need);
                    ladders--;
                }
                else{
                    if(!pq.empty() and pq.top() < need and bricks>=pq.top()){
                        bricks-=pq.top();
                        pq.pop();
                        pq.push(need);
                    }
                    else if( bricks>=need){
                        bricks-=need;
                    }
                    
                    else
                        break;
        
                }
            }
            ans = i + 1;
        }
            // if(i==n-1 and heights[i] <=heights[i-1])
            //     ans++;
        return ans;
    }
};