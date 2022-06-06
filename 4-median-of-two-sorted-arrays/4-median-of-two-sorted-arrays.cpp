class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        
        if(m<n){
            nums1.swap(nums2);
        }
        
        n = nums1.size(), m = nums2.size();
        int low = 0 , high=n;
        while(low<=high){
            int key1 = low + (high-low)/2;
            int key2 = (n+m+1)/2 - key1;
            
            int l1 = key1==0 ? INT_MIN : nums1[key1-1]; 
            int l2 = key2==0 ? INT_MIN : nums2[key2-1]; 
            int r1 = key1==n ? INT_MAX : nums1[key1]; 
            int r2 = key2==m ? INT_MAX : nums2[key2]; 
            
            if(l1<=r2 and l2<=r1){
                if((n+m)%2==0){
                    return (max(l1,l2) + min(r1,r2))/2.0;
                }
                return max(l1,l2);
            }
            else if(l1>r2)
                high = key1-1;
            else
                low = key1+1;
        
        }
        return 0.00;
        
    }
};