class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = 1e9,k;
        
        while(low<=high){
            k = low + (high-low)/2;
            
            int hour=0;
            
            for(int i=0;i<piles.size();i++){
                hour += ceil(1.0*piles[i]/k);
            }
            if(hour>h){
               low = k+1;
            }
            else
                high =k-1;
                
        }
        return low;
    }
};