class Solution {
public:
    int rotatedDigits(int n) {
        unordered_map<int , int> rotated_map = {
            {0,0}, {1,1}, {8,8}, {2,5}, {5,2}, {6,9}, {9,6}
        };

        int ans = 0;

        for(int i = 1; i <= n; i++){
            int temp = i;
            bool valid = true;
            bool changed = false;

            while(temp){
                int d = temp % 10;
                temp /= 10;

                if (rotated_map.find(d) == rotated_map.end()){
                    valid = false;
                    break;
                }

                if (rotated_map[d] != d){
                    changed = true;
                }
            }

            if (valid && changed){
                ans++;
            }
        }
        return ans;
    }
};