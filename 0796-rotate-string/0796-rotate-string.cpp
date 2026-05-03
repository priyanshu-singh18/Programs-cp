class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();

        if (s == goal){
            return true;
        }

        for (int i = 1 ; i < n ; i++){
            string pre = s.substr(0 , i);
            string post = s.substr(i , n);

            string f = post + pre ; 
            if(f == goal){
                return true;
            }
        }
        return false;
    }
};