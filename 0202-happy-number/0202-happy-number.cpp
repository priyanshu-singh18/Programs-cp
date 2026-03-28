class Solution {
public:

    int square(int n ){
        int res = 0 ;

        while(n){
            int rem = n%10;
            res+=rem*rem;
            n = n/10;
        }
        return res;
    }

    bool isHappy(int n) {
        int slow = n ; 
        int fast = n ; 

        do {
            slow = square(slow);
            fast = square(square(fast));
        }
        while(slow!=fast);

        return slow == 1;

    }
};