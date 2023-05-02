class Solution {
public:
    int arraySign(vector<int>& nums) {
        int negCount = 0;
        for(int i : nums){
            if(i < 0) negCount++;
            if(i == 0) return 0;
        }
        if(negCount%2 == 1) return -1;
        return 1;
    }
};
