class Solution {
public:
    bool canPlaceFlowers(vector<int>& fb, int n) {
        int i = -1;
        while(++i < fb.size()){
            if(fb[i] == 0 && (i == 0 || fb[i-1] == 0) && (i == fb.size()-1 || fb[i+1] == 0)){
                ++i;
                if(--n <= 0) return true;
            }
        }
        return n<=0;
    }
};
