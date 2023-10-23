class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 1) return true;
        if(n%2 == 1 || n < 0) return false;
        int cnt0 = 0;
        while(n = n>>1)
            if(n&1) break;
            else cnt0++;
        return (n == 1 && cnt0%2 == 1);
    }
};
