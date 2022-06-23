class Solution {
public:
    
    bool possible(vector<int>& cookies, int mid, int k){
        int studs = 1;
        int cook=0;
        for(int i=0;i<cookies.size();i++){
            // if(cookies[i] + cook <= mid ){
            //     cook+=cookies[i];
            // }
            // else{
            //     cook = cookies[i];
            //     studs++;
            //     if(studs > k)
            //         return false;
            // }
            
            cook+= cookies[i];
            
            if(cook > mid){
                cook = cookies[i];
                studs++;
            }
            if(studs > k)
                return false;
        }
        return true;
    }
    
    int bs(vector<int>& cookies, int k ){
        int sum = 0 ,  maxi = 0;
        int ans  = 0;
        int n = cookies.size();
        
        
        for(auto x : cookies){
            sum+=x;
            maxi = max(x, maxi);
        }
        
        int low = maxi , high = sum , mid ;
        
        while(low<=high){
            mid = low + (high-low)/2;
            
            if(possible(cookies,mid,k)){
                high = mid -1;
                ans = mid;
            }
            else
                low = mid+1;
        }
        return ans;
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        sort(cookies.begin(),cookies.end());
        int mini = INT_MAX;
        
        do {
            mini = min ( mini , bs(cookies,k));
        } while(next_permutation(cookies.begin(),cookies.end()));
        
        return mini;
    }
};