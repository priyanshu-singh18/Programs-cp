class Solution {
public:
    
    void merge(vector<int>& nums, int l, int mid, int r){
        
        int n1 = mid-l+1, n2 = r-mid;
        int arr1[n1],arr2[n2];
        
        for(int i=0;i<n1;i++){
            arr1[i] = nums[l + i];
        }
        for(int i=0;i<n2;i++){
            arr2[i] = nums[mid+1 + i];
        }
        int i=0,j=0,k=l;
        
        while(i<n1 and j<n2){
            if(arr1[i] < arr2[j]){
                nums[k] = arr1[i];
                i++,k++;
            }    
            else if(arr2[j] <= arr1[i]){
                nums[k] = arr2[j];
                j++,k++;
            }
        }
        
        while(i<n1){
          
                nums[k] = arr1[i];
                i++,k++;
            
        }
          while(i<n1){
      
                nums[k] = arr2[j];
                j++,k++;
            
        }
    } 
    
    void mergeSort(vector<int>& nums, int l , int r){
        if(l<r){    
            int mid = ( l + r)/2;

            mergeSort(nums, l,mid);
            mergeSort(nums,mid+1,r);

            merge(nums,l,mid,r);
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};