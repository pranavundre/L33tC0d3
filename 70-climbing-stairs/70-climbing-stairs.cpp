class Solution {
public:
    int climbStairs(int n) {
        int fib0 = 0, fib1 = 1, fibn;
        for(int i = 0; i < n; i++){
            fibn = fib1 + fib0;
            fib0 = fib1;
            fib1 = fibn;
        }
        return fibn;
    }
};