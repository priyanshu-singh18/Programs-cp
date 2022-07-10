class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        
        int start = intervals[0][0],end = intervals[0][1], n = intervals.size();
        if(n==1)
            return intervals;
        vector<vector<int>> res;
        
        for(int i=1;i<intervals.size();i++){
            if(end< intervals[i][0]){
                res.push_back({start,end});
                start = intervals[i][0];
                end = max(end , intervals[i][1]);  
                
            
            }
            else{
                end = max(end , intervals[i][1]);  
            }
            
            if(i==n-1)
                res.push_back({start,end});
        }
        return res;
    }
};