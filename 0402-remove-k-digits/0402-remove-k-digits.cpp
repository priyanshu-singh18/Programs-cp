class Solution {
public:
    string removeKdigits(string num, int k) {
        // stack
        string result = "";

        for(char digit : num){

            while(!result.empty() && result.back() > digit && k > 0 ){
                result.pop_back();
                k--;
            }

            if(!result.empty() || digit != '0'){
                result.push_back(digit);
            }
        }

        while(k>0 && !result.empty()){
            result.pop_back();
            k--;
        }

        return result.empty() ? "0" : result;
    }
};