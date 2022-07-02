class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        
        int n1 = hc.size(), n2  = vc.size();
        
        
        
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
        
         int max1 = INT_MIN, max2 = INT_MIN;
        
        for(int i=0;i<=hc.size();i++){
            if(i==n1){
                max1 =max(max1, h - hc[n1-1]);
                continue;
            }
            int temp = i==0 ? hc[i] : hc[i] - hc[i-1];
            max1 = max(max1, temp);
        }
        for(int i=0;i<=vc.size();i++){
            if(i==n2){
                max2 =max(max2, w - vc[n2-1]);
                continue;
            }
            int temp = i==0 ? vc[i] : vc[i]-vc[i-1];
            max2 = max(max2, temp);
        }
        
        return (1ll*max1*max2)%1000000007;
    }
};