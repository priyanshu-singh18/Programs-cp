class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end() );
        int n = arr.size();
        long long int ans = 0,mod = 1e9+7;
        
        for(int i=0;i<n;i++){
            int temp = target - arr[i];
            int front = i+1,back = n-1;
            
            while(front<back){
                int sum = arr[front] + arr[back];
                
                if(sum > temp){
                    back--;
                }
                else if(sum< temp){
                    front++;
                }
                else if(arr[front]!=arr[back]){
                    int l = 1, r = 1;
                    
                    while(front+1 < back && arr[front] == arr[front+1]){
                        front++;
                        l++;
                    }
                    while(back-1 > front and arr[back] == arr[back-1]){
                        back--;
                        r++;
                    }
                    ans += l*r;
                    ans = ans%mod;
                    back--;
                    front++;
                }
                else{
                    ans+= ((back-front + 1)*(back-front))/2;
                    ans = ans % mod;
                    break;
                }
            }
        }
        return ans;
    }
};