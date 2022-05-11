class Solution {
public:
    
//     int ans = 0;
//     vector<string> vowels = {"a","e","i","o","u"};
    
//     void solve(int i, int n , string& temp){
//         if(i>=5 || temp.size()>n){
//             if(temp.size()==n){
//                 ans++;
//             }
//             return;
//         }
        
//         temp+=vowels[i];
//         solve(i,n,temp);
//         solve(i+1,n,temp);
        
//         temp.pop_back();
//         solve(i,n,temp);
//     }
            //TLE
    
   
    int countVowelStrings(int n) {
    vector<int> dp(5,1);
        for(int i = 0; i < n; i++){
            for(int j = 1; j <5; j++){
                dp[j] += dp[j-1];
            }
        }
        return dp[4];

    
    }
};