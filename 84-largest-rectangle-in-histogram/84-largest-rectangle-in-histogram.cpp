class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> ngr,ngl;
        int n = heights.size();
        
        stack<pair<int,int>> sr,sl;
        
        for(int i=0;i<n;i++){
            if(sl.empty())
                ngl.push_back(-1);
            else if(!sl.empty() and sl.top().first<heights[i])
                ngl.push_back(sl.top().second);
            else{
                while(!sl.empty() and sl.top().first>=heights[i])
                    sl.pop();
                
                if(sl.empty())
                    ngl.push_back(-1);
                else 
                    ngl.push_back(sl.top().second);
            }
            sl.push({heights[i],i});
        }
        
        for(int i=n-1;i>=0;i--){
            if(sr.empty())
                ngr.push_back(n);
            else if(!sr.empty() and sr.top().first<heights[i])
                ngr.push_back(sr.top().second);
            else{
                while(!sr.empty() and sr.top().first>=heights[i])
                    sr.pop();
                
                if(sr.empty())
                    ngr.push_back(n);
                else 
                    ngr.push_back(sr.top().second);
            }
            sr.push({heights[i],i});
        }
        
        reverse(ngr.begin(),ngr.end());
        int ans = 0 ;
        for(int i=0;i<n;i++){
            ans = max(ans, (ngr[i]-ngl[i]-1)*heights[i]);
        }
        return ans;
    }
};